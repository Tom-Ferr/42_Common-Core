import { Body, Controller, Delete, Get, Param, Post, Put, UseGuards } from '@nestjs/common';
import { GameService } from './game.service';
import JwtTwoFactorGuard from 'src/authentication/jwt-two-factor.guard';
import CreateGameDto from './dto/creategame.dto';
import UpdateGameDto from './dto/updategame.dto';
import FindOneParams from 'src/utils/findOneParams';


@Controller('game')
export class GameController {
    constructor(private readonly gameService: GameService) {}

    @Post()
    // @UseGuards(JwtTwoFactorGuard)
    async gameCreate(@Body() createGame: CreateGameDto){
      return this.gameService.create(createGame)
    }

    @Put()
    // @UseGuards(JwtTwoFactorGuard)
    async gameUpdate(@Body() updateGame: UpdateGameDto){
      return this.gameService.update(updateGame)
    }

    @Delete()
    // @UseGuards(JwtTwoFactorGuard)
    async gameEnd(@Body() updateGame: UpdateGameDto){
      this.gameService.delete(updateGame.id)
    }

    @Get(':id')
    async gameWatch(@Param('id')id: string) {
      if (isNaN(+id))
        return this.gameService.getGameByPlayer(id);
      return this.gameService.watch(Number(id));
    }

    @Get()
    getActiveGames() {
    return this.gameService.getActiveGames();
  }

}
