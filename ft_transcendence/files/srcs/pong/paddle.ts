/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paddle.ts                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:12:21 by tde-cama          #+#    #+#             */
/*   Updated: 2022/01/24 18:12:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


import P5 from 'p5'
export class Paddle {

   x: number
   y: number
   height: number
   width: number
   position: number
   isOnMove: boolean
   score: number
   yPosition: number
   winHeight: number
	constructor(p5: P5, position: number) {
		this.height = p5.windowHeight * 25/100
		this.width = this.height * 10/100
		this.x = p5.windowWidth * position
		this.y = (p5.windowHeight / 2) - (this.height / 2)
		this.position = position
		this.isOnMove = false
		this.score = 0
		this.winHeight = p5.windowHeight
	}

	update(p5: P5) {
		if(p5.windowHeight != this.winHeight){
			this.y = this.yPosition * p5.windowHeight
			this.winHeight = p5.windowHeight
		}
		this.yPosition = this.y / p5.windowHeight
		this.x = p5.windowWidth * this.position
		this.height = p5.windowHeight * 25/100
		this.width = this.height * 10/100
		if (this.isOnMove == true) {
			if(this.y + this.height <= p5.windowHeight && p5.keyCode == p5.DOWN_ARROW){
				this.y += p5.windowHeight * 2/100 
			}
			else if(this.y >= 0 && p5.keyCode == p5.UP_ARROW){
				this.y -= p5.windowHeight * 2/100
			}
		}
		this.display(p5)
	}

	display(p5: P5){
		p5.stroke(255)
		p5.rect(this.x, this.y, this.width, this.height)
	}

};