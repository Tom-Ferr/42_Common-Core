/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.ts                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:12:26 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/15 23:54:20 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import P5 from 'p5'
import { Mids } from './mids'
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
    midsIsOn: boolean
    mid_top: Mids
    mid_bottom: Mids

    constructor(p5, player1: Paddle, mids: boolean){
        this.x = p5.windowWidth / 2
        this.y = p5.windowHeight / 2
        this.width = player1.height * 15/100
        this.radius = this.width / 2
        this.winHeight = p5.windowHeight
        this.midsIsOn = mids
        if(mids){
            this.mid_top = new Mids(p5, 1)
            this.mid_bottom = new Mids(p5, -1)
        }

        this.start(p5)
    }

    update = (p5, player1: Paddle, player2: Paddle,) => {
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
        if(this.midsIsOn){
            if(this.hitPlayer1(this.mid_bottom) || this.hitPlayer2(this.mid_bottom))
                this.reflect(p5, this.mid_bottom)
            else if(this.hitPlayer1(this.mid_top) || this.hitPlayer2(this.mid_top))
                this.reflect(p5, this.mid_top)
        }
        this.xPosition = this.x / p5.windowWidth
        this.yPosition = this.y / p5.windowHeight
    }

    move = () => {
        this.x += this.xSpeed
        this.y += this.ySpeed
    }

    start = (p5) => {
        const m: number[] = [-1, 1]
        this.xSpeed = Math.floor(Math.random() * (p5.windowWidth * 1/100)) + (p5.windowWidth * 0.5/100)
        this.ySpeed = Math.floor(Math.random() * (p5.windowWidth * 1/100)) + (p5.windowHeight * 0.15/100)
        this.xSpeed *= m[Math.floor(Math.random() * 2)]
        this.ySpeed *= m[Math.floor(Math.random() * 2)]
    }

    reflect = (p5, player) => {
        if(this.y <= (player.y + player.height) * 30 / 100 && this.ySpeed > 0)
            this.ySpeed *= -1
        else if(this.y >= (player.y + player.height) * 70 / 100 && this.ySpeed <  0)
            this.ySpeed *= -1
        if(this.x > player.x && this.xSpeed < 0)
            this.xSpeed *= -1
        else if(this.x < player.x + player.width && this.xSpeed > 0)
            this.xSpeed *= -1
        if(this.xSpeed <= p5.windowWidth * 5 /100 && this.xSpeed > 0)
            this.xSpeed += (Math.floor(Math.random() * 15) + 5) / 100 * this.xSpeed
        else if(this.xSpeed * -1 <= p5.windowWidth * 5 /100 && this.xSpeed < 0)
            this.xSpeed += (Math.floor(Math.random() * 15) + 5) / 100 * this.xSpeed
        if(this.ySpeed <= p5.windowWidth * 5 /100 && this.ySpeed > 0)
            this.ySpeed += (Math.floor(Math.random() * 15) + 5) / 100 * this.ySpeed
        else if(this.ySpeed * -1 <= p5.windowWidth * 5 /100 && this.ySpeed < 0)
            this.ySpeed += (Math.floor(Math.random() * 10) + 5) / 100 * this.ySpeed

    }

    reset = (p5, player1: Paddle, player2: Paddle) => {
        if (this.x - this.radius <= 0)
            ++player2.score
        else
            ++player1.score
        this.x = p5.windowWidth / 2
        this.y = p5.windowHeight / 2 
        this.start(p5)
    }

    hitPlayer1 = (player1): boolean => {
        if(this.x + this.radius >= player1.x){
            if(this.x - this.radius <= player1.x + player1.width && this.onPaddle(player1))
               return true 
        }
        return false
    }
    hitPlayer2 = (player2): boolean => {
        if(this.x - this.radius <= player2.x + player2.width){
            if(this.x + this.radius >= player2.x && this.onPaddle(player2))
               return true 
        }
        return false
    }
    onPaddle = (player): boolean => {
        if( (this.y + this.width >= player.y && this.y + this.width <= player.y + player.height)
        || this.y - this.width >= player.y && this.y - this.width <= player.y + player.height) 
            return true
        return false
    }
    
};