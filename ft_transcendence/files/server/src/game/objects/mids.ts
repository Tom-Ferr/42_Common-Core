/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mids.ts                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:12:21 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/13 10:48:08 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


import P5 from 'p5'
export class Mids {

   x: number
   y: number
   height: number
   width: number
   position: number = 50 / 100
	constructor(p5, yPosition: number) {
		this.height = p5.windowHeight * 30/100
		this.width = this.height * 10/100
		this.x = (p5.windowWidth * this.position) - (this.width/2)
		if (yPosition < 0)
			this.y = p5.windowHeight - this.height
		else
			this.y = 0
	}

};