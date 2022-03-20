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
   
  @WebSocketGateway({
    cors: {
      origin: 'http://localhost:8080',
      namespace: '/pong'
    },
  })
  export class GameGateway implements OnGatewayConnection {

    @WebSocketServer()
    server: Server

    private gameLogic: GameLogic

    private player1 = { id: null }
    private player2 = { id: null }

    constructor (
      private  gameService: GameService){}

   
    async handleConnection(socket: Socket) {
        if(this.player1.id === null){
          console.log("p1 connected")
          this.player1.id = socket.id
          this.gameLogic = new GameLogic()
          this.gameLogic.init()
          
        // }
        // else if(this.player2.id === null){
        //   console.log("p2 connected")
        //   this.player2.id = socket.id
          this.gameRun()
        }
      }
   
    @SubscribeMessage('player-event')
    async movePlayer(
        @MessageBody() data: any,
        @ConnectedSocket() socket: Socket,
    ) 
        {
          
          if(socket.id === this.player1.id){
            this.gameLogic.player1.isOnMove = data.isPressed
            this.gameLogic.player1.eventKey = data.key
          }
          else if(socket.id === this.player2.id){
            this.gameLogic.player1.isOnMove = data.isPressed
            this.gameLogic.player1.eventKey = data.key
          }

        }
    async gameRun(){

      while(this.gameLogic.player1.score < 10 && this.gameLogic.player2.score < 10){
        this.gameLogic.calculation()
        await this.sleep(30)
        this.server.emit('game-refresh', {p1: this.gameLogic.player1, p2: this.gameLogic.player2, ball: this.gameLogic.ball})
      }
      console.log('end')
    }

    private sleep(ms: number){
      return new Promise(resolve => setTimeout(resolve, ms));
    }

  }