/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.ts                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:12:26 by tde-cama          #+#    #+#             */
/*   Updated: 2022/01/24 23:30:19 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import P5 from 'p5'
import { Paddle } from './paddle'
export class Ball{

    x: number
    y: number
    width: number
    private height: number
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
        this.height = this.width
        this.radius = this.width / 2
        this.winHeight = p5.windowHeight
        this.start(p5)
    }

    update = (p5: P5, player1: Paddle, player2: Paddle) => {
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
        if(this.x >= player1.x){
            if(this.x - this.radius <= player1.x + player1.width && this.y >= player1.y && this.y <= player1.y + player1.height ){
               this.reflect(p5) 
            }

        }
        if(this.x <= player2.x + player2.width){
            if(this.x + this.radius >= player2.x && this.y >= player2.y && this.y <= player2.y + player2.height ){
               this.reflect(p5) 
            }
        }
        // if (this.y + this.radius >= player2.y && this.x + this.radius >= player2.x)
        //     this.ySpeed *= -1

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
        this.xSpeed = p5.random(p5.windowWidth * 0.5/100, p5.windowWidth * 1.5/100)
        this.ySpeed = p5.random(p5.windowHeight * 0.25/100, p5.windowHeight * 1.5/100)
        this.xSpeed *= p5.random(m) 
        this.ySpeed *= p5.random(m) 
    }

    reflect = (p5: P5) => {
        this.xSpeed *= -1 
        this.xSpeed += p5.random(-1, 2)
        this.ySpeed += p5.random(-1, 2)
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
    
};