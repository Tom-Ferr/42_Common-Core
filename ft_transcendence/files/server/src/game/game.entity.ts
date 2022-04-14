/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.entity.ts                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:24:16 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/13 21:12:41 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Column, Entity, PrimaryGeneratedColumn } from 'typeorm';
 
@Entity()
class Game {
  @PrimaryGeneratedColumn()
  public id: number;

  @Column({nullable: true, type: 'decimal'})
  public p1Position: number;
 
  @Column({nullable: true, type: 'decimal'})
  public p2Position: number;
  
  @Column({nullable: true, type: 'decimal'})
  public ballXPosition: number;

  @Column({nullable: true, type: 'decimal'})
  public ballYPosition: number;
 
  @Column({unique: true})
  public p1: string;
 
  @Column({nullable: true, unique: true})
  public p2: string;

  @Column({default: 0})
  public p1Score: number;
 
  @Column({default: 0})
  public p2Score: number;

  @Column({default: false})
  public p2IsReady: boolean;

  @Column({default: false})
  public mids: boolean;

  @Column({default: false})
  public pill: boolean;
  
}
 
export default Game;