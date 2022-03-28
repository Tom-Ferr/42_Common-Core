import {
    ConnectedSocket,
    MessageBody, OnGatewayConnection,
    SubscribeMessage,
    WebSocketGateway,
    WebSocketServer,
  } from '@nestjs/websockets';
  import io, { Server, Socket } from 'socket.io';
  import { ChatService } from './chat.service';
  import * as randomId from 'random-id'
  import { UsersService } from 'src/users/users.service';
   
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
      private readonly chatService: ChatService,
      private readonly userService: UsersService,
    ) {
      this.map = new Map<string, string>()
    }
   
    async handleConnection(socket: Socket) {
      if(socket.handshake.query){

        const {name} = socket.handshake.query
        this.map.set(name, socket.id)
      }
      else{
        let sessionID = socket.handshake.auth.sessionID;
        let username = socket.handshake.auth.username;
        let userID = socket.handshake.auth.userID;
        if (sessionID) {
          // find existing session
          const session = await this.userService.findSession(sessionID);
          if (session) {
            userID = session.id;
            username = session.name;
          }
        }
        else{
          // create new session
          sessionID = randomId();
          this.userService.udpateSessionID(sessionID, userID)
        }
        socket.emit("session", {
          sessionID: sessionID,
          userID: userID,
        });
        socket.join(userID.toString())
      }
    }

    handleDisconnect(socket: Socket){
      console.log(socket.handshake.auth.username, ' has disconnected')
    }
   
    @SubscribeMessage('private-message')
    async sendPrivateMessage(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
      const target = await this.userService.getByName(content.to)
      if(target.block_list.includes(content.from) === false){
        const mail = await this.userService.saveMail({from: content.from, message: content.message}, target.id)
        this.server.to(target.id.toString()).emit('receive_private-message', mail);
      }
    }

    @SubscribeMessage('block-user')
    async blockUser(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
        this.userService.blockUser(content.name, content.id)
      }

    @SubscribeMessage('ban-user')
    async banUser(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
        this.chatService.banUser(content.name, content.id)
      }

    @SubscribeMessage('unban-user')
    async unBanUser(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
        this.chatService.unBanUser(content.name, content.id)
      }

    @SubscribeMessage('mute-user')
    async muteUser(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
        this.chatService.muteUser(content.name, content.id)
        setTimeout(() => {
          this.chatService.unMuteUser(content.name, content.id)
        }, content.time)
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