/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chat.service.ts                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:23:20 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/06 20:16:41 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Injectable } from '@nestjs/common';
import { AuthenticationService } from '../authentication/authentication.service';
import { Socket } from 'socket.io';
import { parse } from 'cookie';
import { WsException } from '@nestjs/websockets';
import { InjectRepository } from '@nestjs/typeorm';
import Chat from './chat.entity';
import User from '../users/user.entity';
import { Repository } from 'typeorm';
import CreateChatDto from './dto/createchat.dto';
import UpdateChatDto from './dto/updatechat.dto';
import * as randomId from 'random-id';
import * as bcrypt from 'bcrypt'

@Injectable()
export class ChatService {

  constructor(
    @InjectRepository(Chat)
    private chatRepository: Repository<Chat>
  ){}

  async create(chatData: CreateChatDto){
    let status = 'public'
    if(chatData.password){
      const hashedPassword = await bcrypt.hash(chatData.password, 10);
      chatData = { ...chatData, password: hashedPassword }
      status = 'protected'
    }
    const newChat = await this.chatRepository.create({
      ...chatData,
      id: randomId(),
      ban_list: [],
      mute_list: [],
      status: status
    });
    await this.chatRepository.save(newChat);
    newChat.password = undefined;
    return newChat;
  }

  async update(chatUpdate: UpdateChatDto){
    console.log(chatUpdate)
      if(chatUpdate.password){
        const hashedPassword = await bcrypt.hash(chatUpdate.password, 10);
        chatUpdate = { ...chatUpdate, password: hashedPassword }
      }
      await this.chatRepository.update(chatUpdate.id, chatUpdate);
      const updatedChat = await this.chatRepository.findOne(chatUpdate.id);
      updatedChat.password = undefined
      return updatedChat
  }

  async delete(id: string) {
      await this.chatRepository.delete(id);
  }

  async getActiveChats() {
    let chatList = await this.chatRepository.find();
    chatList.forEach( (value, index, array) => {
      array[index] = {...value, password: undefined}
    });
    return chatList;
  }

  async muteUser(username: string, id: string) {
    const {mute_list} = await this.chatRepository.findOne({id})
    mute_list.push(username)
    this.chatRepository.update(id, {mute_list: mute_list});
    return mute_list
  }
  async unMuteUser(username: string, id: string) {
    const {mute_list} = await this.chatRepository.findOne({id})
    const index = mute_list.indexOf(username, 0);
    if (index > -1) {
      mute_list.splice(index, 1);
    }
    this.chatRepository.update(id, {
      mute_list: mute_list
    });
    return mute_list
  }

  async updateAdms(adms: string[], id: string) {
    this.chatRepository.update(id, {adms: adms});
    return adms
  }

  async updateBanList(ban: string[], id: string) {
    this.chatRepository.update(id, {ban_list: ban});
    return ban
  }

  async checkPassword(plainTextPassword: string, id: string) {
    const {password} = await this.chatRepository.findOne({id})
    return await bcrypt.compare(plainTextPassword, password);
  }

  async getRoomtByID(id: string){
    const room = await this.chatRepository.findOne({id})
    if(room)
      room.password = undefined
    return room
  }
}