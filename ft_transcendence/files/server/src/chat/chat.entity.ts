import { Column, Entity, ManyToOne, PrimaryGeneratedColumn } from 'typeorm';
import User from '../users/user.entity';
 
@Entity()
class Chat {
  @PrimaryGeneratedColumn()
  public id: number;
 
  @Column()
  public owner: string;
 
  @Column({nullable: true})
  public password: string;
}
 
export default Chat;