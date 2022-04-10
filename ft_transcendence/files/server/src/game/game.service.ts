/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.service.ts                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:24:39 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/10 12:00:53 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Injectable } from "@nestjs/common";
import { LessThan, Repository } from "typeorm";
import { InjectRepository } from '@nestjs/typeorm';
import CreateGameDto from "./dto/creategame.dto"
import UpdateGameDto from "./dto/updategame.dto";
import Game from "./game.entity";

@Injectable()
export class GameService{

    constructor(
        @InjectRepository(Game)
        private gameRepository: Repository<Game>
    ){}

    async create(gameData: CreateGameDto){
        const newGame = await this.gameRepository.create(gameData);
        await this.gameRepository.save(newGame);
        return newGame;
    }

    async update(gameUpdate: UpdateGameDto){
        await this.gameRepository.update(gameUpdate.id, gameUpdate);
        const updatedGame = await this.gameRepository.findOne(gameUpdate.id);
        return updatedGame
    }

    async delete(id: number) {
        await this.gameRepository.delete(id);
    
    }

    async watch(id: number){
        const game = await this.gameRepository.findOne(id);
        return game;
    }

    async getGameByPlayer(p1: string){
        let game = await this.gameRepository.findOne({p1});
        if (!game)
        game = await this.gameRepository.findOne({p2: p1});
        return game;
    }

    async getGameById(id: number){
        const game = await this.gameRepository.findOne({id});
        return game;
    }

    async getActiveGames() {
        return this.gameRepository.find();
    }
     

}