/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paddle.ts                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:12:21 by tde-cama          #+#    #+#             */
/*   Updated: 2022/03/20 06:13:23 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


import P5 from 'p5'
export class Paddle {

   x: number
   y: number
   height: number
   width: number
   position: number
   public isOnMove: boolean
   score: number
   yPosition: number
   winHeight: number
   public eventKey: string
	constructor(p5, position: number) {
		this.height = p5.windowHeight * 25/100
		this.width = this.height * 10/100
		this.x = p5.windowWidth * position
		this.y = (p5.windowHeight / 2) - (this.height / 2)
		this.position = position
		this.isOnMove = false
		this.score = 0
		this.winHeight = p5.windowHeight
	}

	update(p5) {
		this.x = p5.windowWidth * this.position
		this.height = p5.windowHeight * 25/100
		this.width = this.height * 10/100
		if (this.isOnMove == true) {
			if(this.y + this.height <= p5.windowHeight && "ArrowDown" == this.eventKey){
				this.y += p5.windowHeight * 2/100 
			}
			else if(this.y >= 0 && "ArrowUp" == this.eventKey){
				this.y -= p5.windowHeight * 2/100
			}
		}
		this.yPosition = this.y / p5.windowHeight
	}

};