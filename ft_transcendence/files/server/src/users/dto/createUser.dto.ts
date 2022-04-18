/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createUser.dto.ts                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:25:23 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/17 15:34:46 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { IsString, IsNotEmpty, IsOptional, IsArray, IsEmail, isString } from 'class-validator';

class CreateUserDto {
    @IsEmail()
    @IsOptional()
    email?: string;

    @IsString()
    @IsOptional()
    name?: string;

    @IsString()
    @IsOptional()
    password?: string;

    @IsString()
    @IsOptional()
    login?: string
}
   
export default CreateUserDto;