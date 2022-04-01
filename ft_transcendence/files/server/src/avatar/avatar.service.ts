/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avatar.service.ts                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:22:55 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:22:56 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Injectable, HttpException, HttpStatus } from "@nestjs/common";
import Avatar from "./avatar.entity";
import { LessThan, Repository } from "typeorm";
import { InjectRepository } from '@nestjs/typeorm';


@Injectable()
class AvatarService{
    constructor(
        @InjectRepository(Avatar)
        private avatarRepository: Repository<Avatar>
    ){}

    async updateAvatar(userId: number, file) {
        return this.avatarRepository.update(userId, {
          data: file.buffer,
          fileName: file.originalname
        });
    }
   async createAvatar(user_id: number) {
        const newAvatar = await this.avatarRepository.create({id: user_id});
        await this.avatarRepository.save(newAvatar);
        return newAvatar
   }

   async getById(id: number) {
    const avatar = await this.avatarRepository.findOne({ id });
    if (avatar) {
      return avatar;
    }
    throw new HttpException('Avatar with this id does not exist', HttpStatus.NOT_FOUND);
  }

}

export default AvatarService