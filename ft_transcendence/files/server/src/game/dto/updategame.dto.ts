/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updategame.dto.ts                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:24:09 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/10 09:05:29 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class UpdateGameDto {

  id: number;
  p1Position: number;
  p2Position: number;
  ballXPosition: number;
  ballYPosition: number;
  p1: string;
  p2: string;
}
   
export default UpdateGameDto;