/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chat.entity.ts                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:23:05 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:23:06 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Column, Entity, ManyToOne, PrimaryColumn } from 'typeorm';
import User from '../users/user.entity';
 
@Entity()
class Chat {
  @PrimaryColumn()
  public id: string;
 
  @Column()
  public owner: string;

  @Column({nullable: true})
  public status: string;
 
  @Column({nullable: true})
  public password: string;

  @Column('simple-array')
  public ban_list: string[];

  @Column('simple-array')
  public mute_list: string[];
  
  @Column('simple-array')
  public adms: string[];
}
 
export default Chat;