/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sketch.ts                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:12:30 by tde-cama          #+#    #+#             */
/*   Updated: 2022/03/03 20:46:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import P5 from 'p5'
import { Ball } from './ball';
import { Paddle } from './paddle';
import axios from 'axios';
import { useState } from 'react'

const sketch = (p5: P5) => {
  let player1: Paddle
  let player2: Paddle
  let ball: Ball
  let currentPlayer
  const [ gameInfo, setGameInfo ] = useState({})
  const [ playerInfo, setPlayerInfo ] = useState({})

  const loadInfo = async () => {
    await axios.get(`http://localhost:3000/game/${playerInfo.gameID}`, {withCredentials: true})
    .then(response => {
      setGameInfo(response.data)
    })
  }

  const updateInfo = async () => {
    await axios.put(`http://localhost:3000/game`, gameInfo, {withCredentials: true})
  }

  p5.setup = async () => {
    await axios.get('http://localhost:3000/authentication', {withCredentials: true})
    .then(response => {
      setPlayerInfo(response.data)
    })
    await loadInfo()
    player1 = new Paddle(p5, 5/100)
    player2 = new Paddle(p5, 95/100)
    ball = new Ball(p5, player1)
    if (gameInfo.p1 == playerInfo.name)
      currentPlayer = player1
    else if(gameInfo.p2 == playerInfo.name)
      currentPlayer = player2
    else
      currentPlayer = new Paddle(p5, 0)
  }
  
  p5.draw = () => {
    if (!gameInfo.p2){
      p5.textSize(p5.windowWidth * p5.windowHeight * 30/100)
      p5.fill(255)
      p5.text("Waiting for Oponnent", p5.windowWidth * 50/100, p5.windowHeight * 50/100)
      loadInfo()
    }
    else{
      p5.createCanvas(p5.windowWidth, p5.windowHeight);
      p5.background(0)
      displayLine(p5)
      displayScore(p5)
      if(player1.score < 10 && player2.score < 10){
        player1.update(p5)
        player2.update(p5)
        ball.update(p5, player1, player2)
        updateInfo()
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