/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chat.gateway.ts                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:23:10 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/17 15:12:14 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    connectedList: {[key: string]: string[]} = {}

   
    constructor(
      private readonly chatService: ChatService,
      private readonly userService: UsersService,
    ) {
      this.map = new Map<string, string>()
    }
   
    async handleConnection(socket: Socket) {
      const {username} = socket.handshake.auth
      const {id} = await this.userService.getByName(username)
      if(socket.handshake.query.room_id){
        
        const {room_id} = socket.handshake.query
        this.map.set(username, socket.id)
        if(!this.connectedList[room_id.toString()])
          this.connectedList[room_id.toString()] = []
        if(!this.connectedList[room_id.toString()].includes(username))
          this.connectedList[room_id.toString()].push(username)
        this.userService.updateStatus('chatting', id)
        
        
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
        this.userService.updateStatus('online', id)
        socket.emit("session", {
          sessionID: sessionID,
          userID: userID,
        });
        socket.join(userID.toString())
      }
    }

    async handleDisconnect(socket: Socket){
      const {username} = socket.handshake.auth
      const {id} = await this.userService.getByName(username)
      if(socket.handshake.query.room_id){
        const {room_id} = socket.handshake.query
        for (let i = 0; i < this.connectedList[room_id.toString()].length; ++i){
          if(username === this.connectedList[room_id.toString()][i]){
            this.connectedList[room_id.toString()].splice(i, 1)
            break
          }
        }
        this.userService.updateStatus('offline', id)
        this.server.to(room_id).emit('receive_connected', this.connectedList[room_id.toString()]);
      }

    }
   
    @SubscribeMessage('private-message')
    async sendPrivateMessage(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
      const target = await this.userService.getByName(content.to)
      if(target)
        this.userService.saveMail({from: content.from, to: content.to, message: content.message}, content.sender_id)
      if(target.block_list.includes(content.from) === false){
        const mail = await this.userService.saveMail({from: content.from, to: content.to, message: content.message}, target.id)
        this.server.to(target.id.toString()).emit('receive_private-message', mail);
      }
    }

    @SubscribeMessage('get-friend-status')
    async getFriendsStatus(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
        const friends = content.friends
        const ret = []
  
        for(let i = 0; i < friends.length; ++i){
          const {status} = await this.userService.getByName(friends[i])
          ret.push(status)
        }
        this.server.to(socket.id).emit('friend-status-updated', ret);
      }

    @SubscribeMessage('set-adm')
    async setAdm(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {

      const {adms} = await this.chatService.getRoomtByID(content.room_id)
      adms.push(content.target)
      this.server.to(content.room_id).emit('adm-updated', await this.chatService.updateAdms(adms, content.room_id));
      }

      @SubscribeMessage('unset-adm')
    async unSetAdm(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
      const {adms} = await this.chatService.getRoomtByID(content.room_id)
        for(let i = 0; i < adms.length; ++i){
            if(adms[i] === content.target){
              adms.splice(i, 1)
                break;
            }
      }
      this.server.to(content.room_id).emit('adm-updated', await this.chatService.updateAdms(adms, content.room_id));
      }

    @SubscribeMessage('unban-user')
    async banUser(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
      const {ban_list} = await this.chatService.getRoomtByID(content.room_id)
        for(let i = 0; i < ban_list.length; ++i){
            if(ban_list[i] === content.target){
              ban_list.splice(i, 1)
                break;
            }
      }
      this.server.to(content.room_id).emit('ban-updated', await this.chatService.updateBanList(ban_list, content.room_id));
      }

    @SubscribeMessage('ban-user')
    async unbanUser(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {

      const {ban_list} = await this.chatService.getRoomtByID(content.room_id)
      ban_list.push(content.target)
      this.server.to(content.room_id).emit('ban-updated', await this.chatService.updateBanList(ban_list, content.room_id));
      }

    @SubscribeMessage('mute-user')
    async muteUser(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
        await this.chatService.muteUser(content.target, content.room_id)
        setTimeout(() => {
          this.chatService.unMuteUser(content.target, content.room_id)
        }, content.time)
      }

    @SubscribeMessage('join')
    async joinRoom(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
   
      socket.join(content.room_id)
      this.server.to(content.room_id).emit('receive_connected', this.connectedList[content.room_id.toString()]);
    }

    @SubscribeMessage('check-chat-password')
    async checkPassword(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
      let permission: boolean = false
      if(content.password){
        permission = await this.chatService.checkPassword(content.password, content.room_id)

      }
      else if(content.password == undefined){
        permission = true
      }
   
      this.server.to(socket.id).emit('password_checked', {...content, permission: permission});
    }

    @SubscribeMessage('send_message')
    async listenForMessages(
      @MessageBody() content: any,
      @ConnectedSocket() socket: Socket,
    ) {
      const {mute_list} = await this.chatService.getRoomtByID(content.room_id)
      if(mute_list.includes(content.name))
        return ;
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

    @SubscribeMessage('get-profile-data')
    async getProfile(
      @MessageBody() username: string,
      @ConnectedSocket() socket: Socket,
      ) {
        try{
          const user = await this.userService.getByName(username)
          this.server.to(socket.id).emit('recv-profile-data', user);
        }
        catch{
          this.server.to(socket.id).emit('recv-profile-data', {});
        }
    }

  }