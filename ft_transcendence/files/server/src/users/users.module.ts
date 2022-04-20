/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   users.module.ts                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:25:32 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:25:32 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Module } from '@nestjs/common';
import { UsersService } from './users.service';
import { TypeOrmModule } from '@nestjs/typeorm';
import User from './user.entity';
import { AvatarModule } from 'src/avatar/avatar.module';
import AvatarService from 'src/avatar/avatar.service';
 
@Module({
  imports: [
    AvatarModule,
    TypeOrmModule.forFeature([User]),
  ],
  providers: [UsersService],
  exports: [UsersService]
})
export class UsersModule {}