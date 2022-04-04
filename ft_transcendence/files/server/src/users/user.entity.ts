/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.entity.ts                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:25:28 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/04 10:26:39 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Column, Entity, PrimaryGeneratedColumn, JoinColumn, OneToOne } from 'typeorm';
 
@Entity()
class User {
  @PrimaryGeneratedColumn()
  public id: number;

  @Column({ default: false })
  public isTwoFactorAuthenticationEnabled: boolean;
 
  @Column({ nullable: true })
  public twoFactorAuthenticationSecret?: string;
 
  @Column({ unique: true, nullable: true })
  public email?: string;

  @Column({ unique: true, nullable: true })
  public login?: string;
 
  @Column({ unique: true, nullable: true })
  public name?: string;
 
  @Column({nullable: true})
  public password: string;

  @Column({ nullable: true })
  public sessionID: string;

  @Column({ type: "jsonb"})
  public mail: {
    from: string;
    message: string;
  }[]

  @Column({ type: "jsonb", nullable: true})
  public matches: {
    p1: string;
    p1Score: string;
    p2: string;
    p2Score: string;
  }[]

  @Column({ type: "json", default: {wins: 0, losses: 0, draws: 0}})
  public stats: {
    wins: number;
    losses: number;
    draws: number;
  }

  @Column({default: 'online'})
  public status: string

  @Column('simple-array')
  public block_list: string[]

  @Column('simple-array')
  public friend_list: string[]

  @Column({default: 0})
  public level: number

  @Column({type: 'bytea', nullable: true})
  public avatar: Uint8Array;

}
 
export default User;