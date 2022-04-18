/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatechat.dto.ts                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:23:43 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/17 15:52:56 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { IsString, IsNotEmpty, IsOptional, IsArray, isString } from 'class-validator';

class UpdateChatDto {
  
  @IsString()
  id: string;

  @IsString()
  @IsOptional()
  password: string;

  @IsString()
  status: string
}
   
export default UpdateChatDto;