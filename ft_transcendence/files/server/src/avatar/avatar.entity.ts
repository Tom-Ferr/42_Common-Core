/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avatar.entity.ts                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:22:47 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:22:47 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Column, Entity, PrimaryColumn } from 'typeorm';
 
@Entity()
class Avatar {
  @PrimaryColumn()
  public id: number;

  @Column({ nullable: true})
  public fileName: string;

  @Column('bytea' ,{ nullable: true})
  public data: string;
 
}
 
export default Avatar;