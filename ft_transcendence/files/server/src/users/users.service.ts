/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   users.service.ts                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:25:36 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/17 18:30:12 by tde-cama         ###   ########.fr       */
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
import PostgresErrorCode from 'src/database/postgresErrorCode.enum';
 
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

  async getByLogin(login: string) {
    const user = await this.usersRepository.findOne({ login });
    if (user) {
      return user;
    }
    throw new HttpException('User with this login does not exist', HttpStatus.NOT_FOUND);
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

  async addUserName(username: string, id: number) {
    try{
      await this.usersRepository.update(id, {name: username});
      return username
    }
    catch (error) {
      if (error?.code === PostgresErrorCode.UniqueViolation) {
        throw new HttpException('User with that name already exists', HttpStatus.BAD_REQUEST);
      }
      throw new HttpException('Something went wrong', HttpStatus.INTERNAL_SERVER_ERROR);
    }
  }

  async updateFriend(friends: string[], id: number) {
    this.usersRepository.update(id, {friend_list: friends});
    return friends
  }

  async updateBlock(block: string[], id: number) {
    this.usersRepository.update(id, {block_list: block});
    return block
  }

  async updateGameId(gameID: number, id: number) {
    this.usersRepository.update(id, {gameId: gameID});
    return gameID
  }

  async addGameMatch(playerName: string, table) {
    const player = await this.getByName(playerName)
    let stats = player.stats
    if (table.p1Score == table.p2Score)
      stats.draws++
    else if(table.p1 === playerName){
      if (table.p1Score > table.p2Score)
        stats.wins++
      else
        stats.losses++
    }
    else{
      if (table.p1Score < table.p2Score)
        stats.wins++
      else
        stats.losses++
    }
    let matches = player.matches
    matches.push(table)
    let level = player.level
    if(stats.wins > 0 && !(stats.wins % 10 || stats.wins / level == 10))
      level++
    this.usersRepository.update(player.id, {matches: matches, stats: stats, gameId: null, level: level})
    return table
  }

  async updateStatus(user_status: string, id: number){

    this.usersRepository.update(id, {status: user_status});
    return user_status

  }


}