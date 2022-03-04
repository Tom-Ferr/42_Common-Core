import { Column, Entity, PrimaryGeneratedColumn } from 'typeorm';
 
@Entity()
class Game {
  @PrimaryGeneratedColumn()
  public id: number;

  @Column({nullable: true})
  public p1Position: number;
 
  @Column({nullable: true})
  public p2Position: number;
  
  @Column({nullable: true})
  public ballPosition: number;
 
  @Column({unique: true})
  public p1: string;
 
  @Column({nullable: true, unique: true})
  public p2: string;
}
 
export default Game;