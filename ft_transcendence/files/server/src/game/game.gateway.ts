/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.gateway.ts                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:24:22 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/06 10:11:57 by tde-cama         ###   ########.fr       */
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
import { runInThisContext } from 'vm';
   
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

    constructor (
      private  gameService: GameService,
      private  userService: UsersService
    ){}

   
    async handleConnection(socket: Socket) {}
   
    @SubscribeMessage('join')
    async joinRoom(
        @MessageBody() data: any,
        @ConnectedSocket() socket: Socket,
    ) 
        {
          socket.join(data.room_id)

          const gameID = Number(data.room_id)

          if(this.player1[gameID] == undefined){
            console.log("p1 connected")
            this.player1[gameID] = socket.id
            this.gameLogic[gameID] = new GameLogic()
            const {name} = socket.handshake.query
            this.gameLogic[gameID].init()
            this.gameLogic[gameID].player1.name = name.toString()
            
          }
          else if(this.player2[gameID] == undefined){
            console.log("p2 connected")
            this.player2[gameID] = socket.id
            const {name} = socket.handshake.query
            this.gameLogic[gameID].player2.name = name.toString()
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
     async endGame(gameID, room_id){
       const gameTable = {
          p1: this.player1[gameID].name, 
          p1Score: this.player1[gameID].score,
          p2: this.player2[gameID].name, 
          p2Score: this.player2[gameID].score,
        }
        await this.userService.addGameMatch(gameTable.p1, gameTable)
        await this.userService.addGameMatch(gameTable.p2, gameTable)
        this.gameLogic[gameID] = undefined
        this.player1[gameID] = undefined
        this.player2[gameID] = undefined
        this.gameService.delete(room_id)
       await this.sleep(5000)
       this.server.to(room_id).emit('end-game')
     }   
    async gameRun(gameID, room_id){

      while(this.gameLogic[gameID].player1.score < 10 && this.gameLogic[gameID].player2.score < 10){
        this.gameLogic[gameID].calculation()
        await this.sleep(30)
        this.server.to(room_id).emit('game-refresh', {p1: this.gameLogic[gameID].player1, p2: this.gameLogic[gameID].player2, ball: this.gameLogic[gameID].ball})
      }
      this.endGame(gameID, room_id)
    }

    private sleep(ms: number){
      return new Promise(resolve => setTimeout(resolve, ms));
    }

  }