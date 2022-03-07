/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.ts                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:12:26 by tde-cama          #+#    #+#             */
/*   Updated: 2022/03/06 17:21:37 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import P5 from 'p5'
import { Paddle } from './paddle'
export class Ball{

    x: number
    y: number
    width: number
    xSpeed: number
    ySpeed: number
    radius: number
    winHeight: number
    xPosition: number
    yPosition: number

    constructor(p5: P5, player1: Paddle){
        this.x = p5.windowWidth / 2
        this.y = p5.windowHeight / 2
        this.width = player1.height * 15/100
        this.radius = this.width / 2
        this.winHeight = p5.windowHeight
        this.start(p5)
    }

    update = (p5: P5, player1: Paddle, player2: Paddle, dbX: number, dbY: number) => {
        this.x = dbX * p5.windowWidth
        this.y = dbY * p5.windowHeight
        if(this.winHeight != p5.windowHeight){
            this.x = this.xPosition * p5.windowWidth
            this.y = this.yPosition * p5.windowHeight
            this.winHeight = p5.windowHeight 
        }
        this.xPosition = this.x / p5.windowWidth
        this.yPosition = this.y / p5.windowHeight
        this.width = player1.height * 15/100
        if(this.y + this.radius >= p5.windowHeight || this.y - this.radius <= 0){
            this.ySpeed *= -1
        }
        if(this.x - this.radius >= 0 && this.x + this.radius < p5.windowWidth)
           this.move()
        else
            this.reset(p5, player1, player2)
        if(this.hitPlayer1(player1))
            this.reflect(p5, player1)
        else if(this.hitPlayer2(player2))
            this.reflect(p5, player2) 
        this.display(p5)
    }

    display = (p5: P5) => {
        p5.stroke(255)
        p5.ellipse(this.x, this.y, this.width)
    }

    move = () => {
        this.x += this.xSpeed
        this.y += this.ySpeed
    }

    start = (p5: P5) => {
        const m: number[] = [-1, 1]
        this.xSpeed = p5.random(p5.windowWidth * 0.5/100, p5.windowWidth * 1/100)
        this.ySpeed = p5.random(p5.windowHeight * 0.15/100, p5.windowHeight * 1/100)
        this.xSpeed *= p5.random(m) 
        this.ySpeed *= p5.random(m) 
    }

    reflect = (p5: P5, player: Paddle) => {
        if(this.y <= (player.y + player.height) * 30 / 100 && this.ySpeed > 0)
            this.ySpeed *= -1
        else if(this.y >= (player.y + player.height) * 70 / 100 && this.ySpeed <  0)
            this.ySpeed *= -1
        this.xSpeed *= -1 
        this.xSpeed += p5.random(5, 15) / 100 * this.xSpeed
        this.ySpeed += p5.random(5, 15) / 100 * this.ySpeed
    }

    reset = (p5: P5, player1: Paddle, player2: Paddle) => {
        if (this.x - this.radius <= 0)
            ++player2.score
        else
            ++player1.score
        this.x = p5.windowWidth / 2
        this.y = p5.windowHeight / 2 
        this.start(p5)
    }

    hitPlayer1 = (player1: Paddle): boolean => {
        if(this.x >= player1.x){
            if(this.x - this.radius <= player1.x + player1.width && this.onPaddle(player1))
               return true 
        }
        return false
    }
    hitPlayer2 = (player2: Paddle): boolean => {
        if(this.x <= player2.x + player2.width){
            if(this.x + this.radius >= player2.x && this.y >= player2.y && this.onPaddle(player2))
               return true 
        }
        return false
    }
    onPaddle = (player: Paddle): boolean => {
        if(this.y >= player.y && this.y <= player.y + player.height) 
            return true
        return false
    }
    
};