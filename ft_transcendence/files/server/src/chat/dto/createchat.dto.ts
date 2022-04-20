/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createchat.dto.ts                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:23:40 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/17 15:53:06 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { IsString, IsNotEmpty, IsOptional, IsArray } from 'class-validator';
class CreateChatDto {
    @IsString()
    owner: string;

    @IsString()
    @IsOptional()
    password: string;

    @IsArray()
    adms: string[];
}
   
export default CreateChatDto;