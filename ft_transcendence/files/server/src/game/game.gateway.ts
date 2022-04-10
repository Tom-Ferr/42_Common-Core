/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.gateway.ts                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:24:22 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/10 20:27:11 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import {
    ConnectedSocket,
    MessageBody, OnGatewayConnection,
    SubscribeMessage,
    WebSocketGateway,
    WebSocketServer,
  } from '@nestjs/websockets';
  import { Server, Socket } from 'socket.io';
  import { GameService } from './game.service';
  import { GameLogic } from './game.logic'
import { UsersService } from 'src/users/users.service';
   
  @WebSocketGateway({
    cors: {
      origin: 'http://localhost:8080',
    },
    namespace: '/pong'
  })
  export class GameGateway implements OnGatewayConnection {

    @WebSocketServer()
    server: Server

    private gameLogic = {}

    private player1 = {}
    private player2 = {}
    private pause = {}

    constructor (
      private  gameService: GameService,
      private  userService: UsersService
    ){}

   
    async handleConnection(socket: Socket) {}
    async handleDisconnect(socket: Socket){
      const {room_id} = socket.handshake.auth
      const gameID = Number(room_id)
      if(socket.id === this.player1[gameID] || socket.id === this.player2[gameID]){
        this.pause[gameID] = true
        if(socket.id === this.player1[gameID])
          this.player1[gameID] = undefined
        else if(socket.id === this.player2[gameID])
          this.player2[gameID] = undefined
        this.gameService.update({
          id: gameID,
          p1Position: this.gameLogic[gameID].player1.yPosition,
          p2Position: this.gameLogic[gameID].player2.yPosition,
          ballXPosition: this.gameLogic[gameID].ball.xPosition,
          ballYPosition: this.gameLogic[gameID].ball.yPosition,
          p1: this.gameLogic[gameID].player1.name,
          p2: this.gameLogic[gameID].player2.name,
        })
        this.server.to(room_id).emit('disconnection')
      }
    }
   
    @SubscribeMessage('join')
    async joinRoom(
        @MessageBody() data: any,
        @ConnectedSocket() socket: Socket,
    ) 
        {
          socket.join(data.room_id)

          const gameID = Number(data.room_id)

          if(this.player1[gameID] == undefined){
            this.userService.updateGameId(gameID, data.user_id)
            console.log("p1 connected")
            this.player1[gameID] = socket.id
            this.gameLogic[gameID] = new GameLogic()
            const {username} = socket.handshake.auth
            this.pause[gameID] = false
            this.gameLogic[gameID].init()
            this.gameLogic[gameID].player1.name = username.toString()
            
          }
          else if(this.player2[gameID] == undefined){
            this.userService.updateGameId(gameID, data.user_id)
            console.log("p2 connected")
            this.player2[gameID] = socket.id
            const {username} = socket.handshake.auth
            this.gameLogic[gameID].player2.name = username.toString()
            this.gameRun(gameID, data.room_id)
          }

        }
    @SubscribeMessage('player-event')
    async movePlayer(
        @MessageBody() data: any,
        @ConnectedSocket() socket: Socket,
    ) 
        {

          const gameID = Number(data.room_id)
          
          if(socket.id === this.player1[gameID]){
            this.gameLogic[gameID].player1.isOnMove = data.isPressed
            this.gameLogic[gameID].player1.eventKey = data.key
          }
          else if(socket.id === this.player2[gameID]){
            this.gameLogic[gameID].player2.isOnMove = data.isPressed
            this.gameLogic[gameID].player2.eventKey = data.key
          }

        }

    @SubscribeMessage('resume')
    async gameContinue(
        @MessageBody() data: any,
        @ConnectedSocket() socket: Socket,
    ) 
        {
          socket.join(data.room_id)

          const gameID = Number(data.room_id)
          const {username} = socket.handshake.auth
          const gameInfo = await this.gameService.getGameById(gameID)
          if(gameInfo.p1 == username){
            console.log("p1 connected")
            this.player1[gameID] = socket.id
          }
          else if(gameInfo.p2 == username){
            console.log("p2 connected")
            this.player2[gameID] = socket.id
          }
          if(this.player1[gameID] && this.player2[gameID]){
            this.pause[gameID] = false
            this.gameRun(gameID, data.room_id)
            this.server.to(data.room_id).emit('continue')
          }

        }

    @SubscribeMessage('give-up')
    async give_Up(
        @MessageBody() data: any,
        @ConnectedSocket() socket: Socket,
    ) 
        {
          const gameID = Number(data.room_id)
          this.endGame(gameID, data.room_id)
        }

     async endGame(gameID, room_id){
       const gameTable = {
          p1: this.gameLogic[gameID].player1.name, 
          p1Score: this.gameLogic[gameID].player1.score,
          p2: this.gameLogic[gameID].player2.name, 
          p2Score: this.gameLogic[gameID].player2.score,
        }
        await this.userService.addGameMatch(gameTable.p1, gameTable)
        await this.userService.addGameMatch(gameTable.p2, gameTable)
        this.gameLogic[gameID] = undefined
        this.player1[gameID] = undefined
        this.player2[gameID] = undefined
        this.gameService.delete(room_id)
       await this.sleep(3000)
       this.server.to(room_id).emit('end-game')
     }   
    async gameRun(gameID, room_id){

      while(this.gameLogic[gameID].player1.score < 10 && this.gameLogic[gameID].player2.score < 10){
        if(this.pause[gameID])
          break
        this.gameLogic[gameID].calculation()
        await this.sleep(30)
        this.server.to(room_id).emit('game-refresh', {p1: this.gameLogic[gameID].player1, p2: this.gameLogic[gameID].player2, ball: this.gameLogic[gameID].ball})
      }
      if(!this.pause[gameID])
        this.endGame(gameID, room_id)
    }

    private sleep(ms: number){
      return new Promise(resolve => setTimeout(resolve, ms));
    }

  }