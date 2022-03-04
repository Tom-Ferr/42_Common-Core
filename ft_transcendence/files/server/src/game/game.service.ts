import { Injectable } from "@nestjs/common";
import { Repository } from "typeorm";
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
        const game = await this.gameRepository.findOne({p1});
        return game;
    }

    async getActiveGames() {
        return this.gameRepository.find();
    }
     

}