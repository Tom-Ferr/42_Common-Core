/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   authentication.controller.ts                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:21:35 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/06 21:12:47 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Body, Req, Res, Controller, HttpCode, Post, Put, Get, UseGuards } from '@nestjs/common';
import { AuthenticationService } from './authentication.service';
import { RegisterDto } from './dto/register.dto';
import { RequestWithUser } from './requestWithUser.interface';
import { LocalAuthenticationGuard } from './localAuthentication.guard';
import { Response } from 'express';
import { JwtAuthenticationGuard } from './jwt-authentication.guard';
import { UsersService } from 'src/users/users.service';
 
@Controller('authentication')
export class AuthenticationController {
  constructor(
    private readonly authenticationService: AuthenticationService,
    private readonly usersService: UsersService,
  ) {}
 
  @Post('register')
  async register(@Body() registrationData: RegisterDto) {
    return this.authenticationService.register(registrationData);
  }
  
  
  
  @HttpCode(200)
  @UseGuards(LocalAuthenticationGuard)
  @Post('log-in')
  async logIn(@Req() request: RequestWithUser, @Res() response: Response) {
    const {user} = request;
    const cookie = this.authenticationService.getCookieWithJwtToken(user.id);
    response.setHeader('Set-Cookie', cookie);
    user.password = undefined;
    if (user.isTwoFactorAuthenticationEnabled) {
      return response.send();
    }

    return response.send(user); 
  }
  
  @UseGuards(JwtAuthenticationGuard)
  @Get('log-out')
  async logOut(@Req() request: RequestWithUser, @Res() response: Response) {
    response.setHeader('Set-Cookie', this.authenticationService.getCookieForLogOut());
    return response.sendStatus(200);
  }
  @UseGuards(JwtAuthenticationGuard)
  @Get()
  authenticate(@Req() request: RequestWithUser) {
    const user = request.user;
    user.password = undefined;
    return user;
  }
  @UseGuards(JwtAuthenticationGuard)
  @Put('username')
  update(@Req() request: RequestWithUser) {
    const user = request.body;
    return this.usersService.addUserName(user.name, user.id)
  }

  @UseGuards(JwtAuthenticationGuard)
  @Put('friend')
  updateFriend(@Req() request: RequestWithUser) {
    const user = request.body;
    this.usersService.updateFriend(user.friend_list, request.user.id)
    user.password = undefined
    return user;
  }
  @UseGuards(JwtAuthenticationGuard)
  @Put('block')
  updateBlock(@Req() request: RequestWithUser) {
    const user = request.body;
    this.usersService.updateBlock(user.block_list, request.user.id)
    user.password = undefined
    return user;
  }
}