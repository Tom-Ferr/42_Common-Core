/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createchat.dto.ts                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:23:40 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/06 19:18:49 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class CreateChatDto {
    owner: string;
    password: string;
    adms: string[];
}
   
export default CreateChatDto;