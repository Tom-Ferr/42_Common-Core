/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avatar.module.ts                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:22:52 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/18 07:07:28 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Module } from '@nestjs/common';
import { TypeOrmModule } from '@nestjs/typeorm';
import { NestjsFormDataModule } from 'nestjs-form-data';
import { DatabaseController } from './avatar.controller';
import Avatar from './avatar.entity';
import AvatarService from './avatar.service';
 
@Module({
  imports: [TypeOrmModule.forFeature([Avatar]), NestjsFormDataModule],
  controllers: [DatabaseController],
  providers: [AvatarService],
  exports: [AvatarService]
})
export class AvatarModule {}