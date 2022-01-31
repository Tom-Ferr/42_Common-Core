/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sketch.ts                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:12:30 by tde-cama          #+#    #+#             */
/*   Updated: 2022/01/31 11:41:16 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import P5 from 'p5'
import { Ball } from './ball';
import { Paddle } from './paddle';


const sketch = (p5: P5) => {
  let player1: Paddle
  let player2: Paddle
  let ball: Ball
  p5.setup = () => {
    player1 = new Paddle(p5, 5/100)
    player2 = new Paddle(p5, 95/100)
    ball = new Ball(p5, player1)
  }
  
  p5.draw = () => {
    p5.createCanvas(p5.windowWidth, p5.windowHeight);
    p5.background(0)
    displayLine(p5)
    displayScore(p5)
    if(player1.score < 10 && player2.score < 10){
      player1.update(p5)
      player2.update(p5)
      ball.update(p5, player1, player2)
    }
    else{
      p5.textSize(p5.windowWidth * p5.windowHeight * 0.5/10000)
      p5.fill(255)
      if(player1.score >= 10)
        p5.text("Player 1 Wins", p5.windowWidth * 20/100, p5.windowHeight * 50/100) 
      else
        p5.text("Player 2 Wins", p5.windowWidth * 60/100, p5.windowHeight * 50/100) 
    }
  } 

  p5.keyPressed = () => {
    if (p5.keyCode == p5.DOWN_ARROW || p5.keyCode == p5.UP_ARROW){
			player1.isOnMove = true;
		}
  }

  p5.keyReleased = () => {
    if (p5.keyCode == p5.DOWN_ARROW || p5.keyCode == p5.UP_ARROW){
			player1.isOnMove = false;
		}
  }

  function displayLine(p5: P5){
    p5.stroke(255)
    p5.line(p5.windowWidth / 2, 0, p5.windowWidth / 2, p5.windowHeight)
  }
  function displayScore(p5: P5){
    p5.stroke(255)
    p5.textSize(p5.windowWidth * p5.windowHeight * 0.5/10000)
		p5.fill(255)
    p5.text(player1.score, p5.windowWidth * 40/100, p5.windowHeight * 7/100)
    p5.text(player2.score, (p5.windowWidth * 55/100), p5.windowHeight * 7/100)
  }

};
// const myp5 = new P5(sketch)

export default sketch