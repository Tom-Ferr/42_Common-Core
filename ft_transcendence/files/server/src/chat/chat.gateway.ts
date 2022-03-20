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
      namespace: '/chat'
    },
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
   
    @SubscribeMessage('send_message')
    async listenForMessages(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
   
      this.server.emit('receive_message', content);
    }

  }