/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.logic.ts                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:24:30 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/13 19:24:06 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Injectable } from "@nestjs/common";
import { Ball } from "./objects/ball";
import { Pill } from "./objects/pill";
import { Paddle } from "./objects/paddle";


export class GameLogic{

    public player1: Paddle
    public player2: Paddle
    public ball: Ball
    public pill: Pill
    private winRatio = {windowHeight: 720, windowWidth: 1280}


    init = (mids: boolean) => {
        this.player1 = new Paddle(this.winRatio, 5/100)
        this.player2 = new Paddle(this.winRatio, 95/100)
        this.ball = new Ball(this.winRatio, this.player1, mids)
        this.pill = new Pill(this.winRatio, this.player1)
    }

    calculation = () => {
        this.player1.update(this.winRatio)
        this.player2.update(this.winRatio)
        this.ball.update(this.winRatio, this.player1, this.player2)
        if (this.pill.isVisible)
            this.pill.update(this.winRatio, this.player1, this.player2)
    }

}