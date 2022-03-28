import { HttpException, HttpStatus, Injectable } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { Repository } from 'typeorm';
import User from './user.entity';
import CreateUserDto from './dto/createUser.dto';
 
@Injectable()
export class UsersService {
  constructor(
    @InjectRepository(User)
    private usersRepository: Repository<User>
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
      block_list: []
    });
    await this.usersRepository.save(newUser);
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