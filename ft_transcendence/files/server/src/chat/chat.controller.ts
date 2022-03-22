import { Body, Controller, Delete, Get, Param, Post, Put, UseGuards } from '@nestjs/common';
import { ChatService } from './chat.service';
import JwtTwoFactorGuard from 'src/authentication/jwt-two-factor.guard';
import CreatechatDto from './dto/createchat.dto';
import UpdatechatDto from './dto/updatechat.dto';
import FindOneParams from 'src/utils/findOneParams';


@Controller('chat')
export class ChatController {
    constructor(private readonly chatService: ChatService) {}

    @Post()
    // @UseGuards(JwtTwoFactorGuard)
    async chatCreate(@Body() createchat: CreatechatDto){
      return this.chatService.create(createchat)
    }

    @Put()
    // @UseGuards(JwtTwoFactorGuard)
    async chatUpdate(@Body() updatechat: UpdatechatDto){
      return this.chatService.update(updatechat)
    }

    @Delete()
    // @UseGuards(JwtTwoFactorGuard)
    async chatEnd(@Body() updatechat: UpdatechatDto){
      this.chatService.delete(updatechat.id)
    }

    @Get()
    getActivechats() {
    return this.chatService.getActiveChats();
  }

}
