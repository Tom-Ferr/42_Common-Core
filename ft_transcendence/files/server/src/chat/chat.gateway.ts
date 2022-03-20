import {
    ConnectedSocket,
    MessageBody, OnGatewayConnection,
    SubscribeMessage,
    WebSocketGateway,
    WebSocketServer,
  } from '@nestjs/websockets';
  import io, { Server, Socket } from 'socket.io';
  import { ChatService } from './chat.service';
   
  @WebSocketGateway({
    cors: {
      origin: 'http://localhost:8080',
    },
    namespace: '/chat'
  })
  export class ChatGateway implements OnGatewayConnection {
    @WebSocketServer()
    server: Server;

    
   
    constructor(
      private readonly chatService: ChatService
    ) {
    }
   
    async handleConnection(socket: Socket) {
      console.log(socket.handshake.query)
    }
   
    @SubscribeMessage('join')
    async joinRoom(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
   
      socket.join(content.room_id)
    }

    @SubscribeMessage('send_message')
    async listenForMessages(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
   
      this.server.to(content.room_id).emit('receive_message', content);
    }

  }