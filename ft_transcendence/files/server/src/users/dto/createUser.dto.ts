/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createUser.dto.ts                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:25:23 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/03 16:15:56 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class CreateUserDto {
    email?: string;
    name?: string;
    password?: string;
    login?: string
}
   
export default CreateUserDto;