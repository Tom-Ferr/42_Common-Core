/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sketch.ts                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:12:30 by tde-cama          #+#    #+#             */
/*   Updated: 2022/03/07 19:57:46 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import P5 from 'p5'
import { Ball } from './ball';
import { Paddle } from './paddle';
import { Puppet } from './puppet';
import axios from 'axios';

const sketch = (p5: P5) => {
  let player1: Paddle
  let player2: Paddle
  let ball: Ball
  let currentPlayer: Paddle
  let isWatching: boolean = false
  let gameInfo
  let playerInfo
  let isLoaded: boolean = false

  const loadInfo = async () => {
    const {data} =await axios.get(`http://localhost:3000/game/${playerInfo.name}`, {withCredentials: true})
    return data
  }

  const getPlayerInfo = async () => {
    const {data} = await axios.get('http://localhost:3000/authentication', {withCredentials: true})
    return data
  }

  const updateInfo = async () => {
    await axios.put(`http://localhost:3000/game`, {...gameInfo, p2:"teste"}, {withCredentials: true})
  }
  
  p5.setup = async () => {
    playerInfo = await getPlayerInfo()
    gameInfo = await loadInfo()
    if (gameInfo.p1 == playerInfo.name){
      currentPlayer = player1 = new Paddle(p5, 5/100)
      player2 = new Puppet(p5, 95/100)
    }
    else if(gameInfo.p2 == playerInfo.name){
      player1 = new Puppet(p5, 5/100)
      currentPlayer = player2 = new Paddle(p5, 95/100)
    }
    else{
      currentPlayer = player1 = new Puppet(p5, 5/100)
      player2 = new Puppet(p5, 95/100)
      isWatching = true
    }
    ball = new Ball(p5, player1)
    isLoaded = true
  }
  
  p5.draw = async () => {
    if(!isLoaded){
      p5.createCanvas(p5.windowWidth, p5.windowHeight);
      p5.background(0)
      p5.textSize(p5.windowWidth * p5.windowHeight * 0.5/10000)
      p5.fill(255)
      p5.text("Loading...", p5.windowWidth * 40/100, p5.windowHeight * 50/100)
    }

    else if (!gameInfo.p2){
      p5.createCanvas(p5.windowWidth, p5.windowHeight);
      p5.background(0)
      p5.textSize(p5.windowWidth * p5.windowHeight * 0.5/10000)
      p5.fill(255)
      p5.text("Waiting for Oponnent", p5.windowWidth * 35/100, p5.windowHeight * 50/100)
      gameInfo = await loadInfo()
    }
    else{
      gameInfo = await loadInfo()
      p5.createCanvas(p5.windowWidth, p5.windowHeight);
      p5.background(0)
      displayLine(p5)
      displayScore(p5)
      if(player1.score < 10 && player2.score < 10){
        player1.update(p5, gameInfo.p1)
        player2.update(p5, gameInfo.p2)
        ball.update(p5, player1, player2, gameInfo.ballXPosition, gameInfo.ballYPosition)
        if(!isWatching){
          if (currentPlayer === player1)
            gameInfo = {
              ...gameInfo, p1: player1.y,
              ballXPosition: (ball.x / p5.windowWidth),
              ballYPosition: (ball.y /p5.windowHeight)
            }
          else
            gameInfo = {...gameInfo, p2: player2.y}
          await updateInfo()
        }
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
  } 

  p5.keyPressed = () => {
    if (p5.keyCode == p5.DOWN_ARROW || p5.keyCode == p5.UP_ARROW){
			currentPlayer.isOnMove = true;
		}
  }

  p5.keyReleased = () => {
    if (p5.keyCode == p5.DOWN_ARROW || p5.keyCode == p5.UP_ARROW){
			currentPlayer.isOnMove = false;
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