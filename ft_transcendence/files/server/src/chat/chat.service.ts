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

@Injectable()
export class ChatService {

  constructor(
    @InjectRepository(Chat)
    private chatRepository: Repository<Chat>
  ){}

  async create(chatData: CreateChatDto){
      const newChat = await this.chatRepository.create(chatData);
      await this.chatRepository.save(newChat);
      return newChat;
  }

  async update(chatUpdate: UpdateChatDto){
      await this.chatRepository.update(chatUpdate.id, chatUpdate);
      const updatedChat = await this.chatRepository.findOne(chatUpdate.id);
      return updatedChat
  }

  async delete(id: number) {
      await this.chatRepository.delete(id);
  }

  async getActiveChats() {
    return this.chatRepository.find();
}
}