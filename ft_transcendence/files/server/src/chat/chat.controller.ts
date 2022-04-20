/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chat.controller.ts                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:23:02 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/05 19:50:34 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    @Get(':id')
    getRoomById(@Param('id')id: string) {
    return this.chatService.getRoomtByID(id);
  }

}
