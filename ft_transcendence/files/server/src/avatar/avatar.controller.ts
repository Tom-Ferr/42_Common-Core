/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avatar.controller.ts                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:22:43 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:22:44 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Body, Controller, Delete, Get, Res,Param, Req, Post, Put, UseInterceptors, UploadedFile, UseGuards, Response, StreamableFile } from '@nestjs/common';
import JwtTwoFactorGuard from 'src/authentication/jwt-two-factor.guard';
import { createReadStream } from 'fs';
import { join } from 'path';
import AvatarService from './avatar.service';
import { Readable } from 'stream';
import { FileInterceptor } from '@nestjs/platform-express';


@Controller('avatar')
export class DatabaseController {
    constructor(private readonly avatarService: AvatarService) {}

  @Get(':id')
  async getAvatar(@Response({ passthrough: true }) res, @Param('id')id: number){
    let file
    const avatar = await this.avatarService.getById(id)
    if(!avatar.data){
      file = createReadStream(join(process.cwd(), './src/avatar/default.jpeg'));
      res.set({
        'Content-Type': 'image/jpeg',
      });
    }
    else{
      file = Readable.from(avatar.data);
      res.set({
        'Content-Disposition': `inline; filename="${avatar.fileName}"`,
        'Content-Type': 'image'
      })
    }
    return new StreamableFile(file);
  };

  @Put(':id')
  @UseInterceptors(FileInterceptor('myFile'))
  async changeAvatar(@Param('id')id: number, @UploadedFile() file){
    this.avatarService.updateAvatar(id, file)
  };

}

