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
    namespace: '/chatroom'
  })
  export class ChatGateway implements OnGatewayConnection {
    @WebSocketServer()
    server: Server;

    map: Map<string | string[], string>

    
   
    constructor(
      private readonly chatService: ChatService
    ) {
      this.map = new Map<string, string>()
    }
   
    async handleConnection(socket: Socket) {
      const {name} = socket.handshake.query
      this.map.set(name, socket.id)
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

    @SubscribeMessage('send_invitation')
    async sendInvitation(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
      if(this.map.has(content.guest))
        this.server.to(this.map.get(content.guest)).emit('receive_invitation', content);
        
    }
    @SubscribeMessage('invitation_accepted')
    async acceptInvitation(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
        this.server.to(this.map.get(content.host)).emit('invitation_was_accepted', content);
        
    }
    @SubscribeMessage('invitation_declined')
    async declineInvitation(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
      ) {
        this.server.to(this.map.get(content.host)).emit('invitation_was_declined', content);
    }

  }