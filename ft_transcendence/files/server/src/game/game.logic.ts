import { Injectable } from "@nestjs/common";
import { Ball } from "./objects/ball";
import { Paddle } from "./objects/paddle";


export class GameLogic{

    public player1: Paddle
    public player2: Paddle
    public ball: Ball
    private winRatio = {windowHeight: 720, windowWidth: 1280}


    init = () =>{
        this.player1 = new Paddle(this.winRatio, 5/100)
        this.player2 = new Paddle(this.winRatio, 95/100)
        this.ball = new Ball(this.winRatio, this.player1)

    }


    calculation = () => {
        this.player1.update(this.winRatio)
        this.player2.update(this.winRatio)
        this.ball.update(this.winRatio, this.player1, this.player2)
    }

}