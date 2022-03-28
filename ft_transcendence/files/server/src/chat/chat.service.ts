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

@Injectable()
export class ChatService {

  constructor(
    @InjectRepository(Chat)
    private chatRepository: Repository<Chat>
  ){}

  async create(chatData: CreateChatDto){
      const newChat = await this.chatRepository.create({
        ...chatData,
        id: randomId(),
        ban_list: [],
        mute_list: [],
      });
      await this.chatRepository.save(newChat);
      return newChat;
  }

  async update(chatUpdate: UpdateChatDto){
      await this.chatRepository.update(chatUpdate.id, chatUpdate);
      const updatedChat = await this.chatRepository.findOne(chatUpdate.id);
      return updatedChat
  }

  async delete(id: string) {
      await this.chatRepository.delete(id);
  }

  async getActiveChats() {
    return this.chatRepository.find();
  }

  async muteUser(username: string, id: string) {
    const {mute_list} = await this.chatRepository.findOne({id})
    this.chatRepository.update(id, {
      mute_list: [...mute_list, username]
    });
    return [...mute_list, username]
  }
  async unMuteUser(username: string, id: string) {
    const {mute_list} = await this.chatRepository.findOne({id})
    const index = mute_list.indexOf(username, 0);
    if (index > -1) {
      mute_list.splice(index, 1);
    }
    this.chatRepository.update(id, {
      mute_list: [...mute_list]
    });
    return [...mute_list]
  }

  async banUser(username: string, id: string) {
    const {ban_list} = await this.chatRepository.findOne({id})
    this.chatRepository.update(id, {
      ban_list: [...ban_list, username]
    });
    return [...ban_list, username]
  }

  async unBanUser(username: string, id: string) {
    const {ban_list} = await this.chatRepository.findOne({id})
    const index = ban_list.indexOf(username, 0);
    if (index > -1) {
      ban_list.splice(index, 1);
    }
    this.chatRepository.update(id, { ban_list: [...ban_list] });
    return [...ban_list]
  }
}