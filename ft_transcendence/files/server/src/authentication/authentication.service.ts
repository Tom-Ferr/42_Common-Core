/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   authentication.service.ts                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:21:47 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/03 22:15:44 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { UsersService } from "src/users/users.service";
import { HttpException, HttpStatus, Injectable } from '@nestjs/common';
import * as bcrypt from 'bcrypt'
import { JwtService } from "@nestjs/jwt";
import { ConfigService } from "@nestjs/config";
import { TokenPayload } from "./tokenPayload.interface";
import { RegisterDto } from "./dto/register.dto";
import PostgresErrorCode from '../database/postgresErrorCode.enum';

@Injectable()
export class AuthenticationService {
  constructor(
    private readonly usersService: UsersService,
    private readonly jwtService: JwtService,
    private readonly configService: ConfigService
  ) {}
  
  public async getUserFromAuthenticationToken(token: string) {
    const payload: TokenPayload = this.jwtService.verify(token, {
      secret: this.configService.get('JWT_ACCESS_TOKEN_SECRET')
    });
    if (payload.userId) {
      return this.usersService.getById(payload.userId);
    }
  }

  public getCookieWithJwtAccessToken(userId: number, isSecondFactorAuthenticated = false) {
    const payload: TokenPayload = { userId, isSecondFactorAuthenticated };
    const token = this.jwtService.sign(payload, {
      secret: this.configService.get('JWT_ACCESS_TOKEN_SECRET'),
      expiresIn: `${this.configService.get('JWT_ACCESS_TOKEN_EXPIRATION_TIME')}s`
    });
    return `Authentication=${token}; HttpOnly; Path=/; Max-Age=${this.configService.get('JWT_ACCESS_TOKEN_EXPIRATION_TIME')}`;
  }

    public async register(registrationData: RegisterDto) {
      const hashedPassword = await bcrypt.hash(registrationData.password, 10);
      try {
        const createdUser = await this.usersService.create({...registrationData, password: hashedPassword});
        createdUser.password = undefined;
        return createdUser;
      }
      catch (error) {
        if (error?.code === PostgresErrorCode.UniqueViolation) {
          throw new HttpException('User with that email already exists', HttpStatus.BAD_REQUEST);
        }
        throw new HttpException('Something went wrong', HttpStatus.INTERNAL_SERVER_ERROR);
      }
    }

    public async registerThroughOAuth(login: string) {
      try {
        const createdUser = await this.usersService.create({login: login});
        return createdUser;
      }
      catch (error) {
        if (error?.code === PostgresErrorCode.UniqueViolation) {
          throw new HttpException('User with that email already exists', HttpStatus.BAD_REQUEST);
        }
        throw new HttpException('Something went wrong', HttpStatus.INTERNAL_SERVER_ERROR);
      }
    }

    public async getAuthenticatedUser(email: string, plainTextPassword: string) {
        try {
          const user = await this.usersService.getByEmail(email);
          await this.verifyPassword(plainTextPassword, user.password);
          user.password = undefined;
          return user;
        }
        catch (error) {
          throw new HttpException('Wrong credentials provided', HttpStatus.BAD_REQUEST);
        }
    }

    public async getIntraUser(login: string) {
        try {
          const user = await this.usersService.getByLogin(login);
          return user;
        }
        catch (error) {
          throw new HttpException('Could not found user with this login', HttpStatus.BAD_REQUEST);
        }
    }
       
    private async verifyPassword(plainTextPassword: string, hashedPassword: string) {
        const isPasswordMatching = await bcrypt.compare(plainTextPassword, hashedPassword);
        if (!isPasswordMatching) {
          throw new HttpException('Wrong credentials provided', HttpStatus.BAD_REQUEST);
        }
    }
    public getCookieWithJwtToken(userId: number) {
      const payload: TokenPayload = { userId };
      const token = this.jwtService.sign(payload);
      return `Authentication=${token}; HttpOnly; Path=/; Max-Age=${this.configService.get('JWT_EXPIRATION_TIME')}`;
    }
    public getCookieForLogOut() {
      return `Authentication=; HttpOnly; Path=/; Max-Age=0`;
    }
}