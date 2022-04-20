/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.module.ts                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:24:34 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/06 13:25:39 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Module } from '@nestjs/common';
import { GameController } from './game.controller';
import { GameService } from './game.service';
import Game from './game.entity';
import { TypeOrmModule } from '@nestjs/typeorm';
import { GameGateway } from './game.gateway';
import { GameLogic } from './game.logic';
import { UsersModule } from 'src/users/users.module';
 
@Module({
  imports: [TypeOrmModule.forFeature([Game]), UsersModule],
  controllers: [GameController],
  providers: [GameService, GameGateway],
})
export class GameModule {}