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

  @Column({default: false})
  public p2IsReady: boolean;
}
 
export default Game;