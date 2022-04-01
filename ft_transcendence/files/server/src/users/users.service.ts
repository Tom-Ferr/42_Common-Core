/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   users.service.ts                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:25:36 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:25:36 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { HttpException, HttpStatus, Injectable, StreamableFile } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { Repository } from 'typeorm';
import User from './user.entity';
import CreateUserDto from './dto/createUser.dto';
import { createReadStream } from 'fs';
import { join } from 'path';
import AvatarService from 'src/avatar/avatar.service';
 
@Injectable()
export class UsersService {
  constructor(
    private avatarService:  AvatarService,
    @InjectRepository(User)
    private usersRepository: Repository<User>,
  ) {}

  async setTwoFactorAuthenticationSecret(secret: string, userId: number) {
    return this.usersRepository.update(userId, {
      twoFactorAuthenticationSecret: secret
    });
  }

  async turnOnTwoFactorAuthentication(userId: number) {
    return this.usersRepository.update(userId, {
      isTwoFactorAuthenticationEnabled: true
    });
  }
  async turnOffTwoFactorAuthentication(userId: number) {
    return this.usersRepository.update(userId, {
      isTwoFactorAuthenticationEnabled: false
    });
  }
 
  async getById(id: number) {
    const user = await this.usersRepository.findOne({ id });
    if (user) {
      return user;
    }
    throw new HttpException('User with this id does not exist', HttpStatus.NOT_FOUND);
  }
 
  async getByEmail(email: string) {
    const user = await this.usersRepository.findOne({ email });
    if (user) {
      return user;
    }
    throw new HttpException('User with this email does not exist', HttpStatus.NOT_FOUND);
  }

  async getByName(name: string) {
    const user = await this.usersRepository.findOne({ name });
    if (user) {
      return user;
    }
    throw new HttpException('User with this name does not exist', HttpStatus.NOT_FOUND);
  }
 
  async create(userData: CreateUserDto) {
    const newUser = await this.usersRepository.create({
      ...userData, 
      mail: [], 
      block_list: [],
      friend_list: [],
      matches: [],
    });
    await this.usersRepository.save(newUser);
    await this.avatarService.createAvatar(newUser.id)
    return newUser;
  }

  async findSession(sessionID: string){
    const user = await this.usersRepository.findOne({ sessionID });
    if (user)
      return user;
  }

  async udpateSessionID(_sessionid: string, userId: number) {
    return this.usersRepository.update(userId, {
      sessionID: _sessionid
    });
  }

  async saveMail(message , id: number) {
    const {mail} = await this.usersRepository.findOne({id})
    this.usersRepository.update(id, {
      mail: [...mail, message]
    });
    return [...mail, message]
  }

  async blockUser(username: string, id: number) {
    const {block_list} = await this.usersRepository.findOne({id})
    this.usersRepository.update(id, {
      block_list: [...block_list, username]
    });
    return [...block_list, username]
  }


}