import { Column, Entity, ManyToOne, PrimaryColumn } from 'typeorm';
import User from '../users/user.entity';
 
@Entity()
class Chat {
  @PrimaryColumn()
  public id: string;
 
  @Column()
  public owner: string;
 
  @Column({nullable: true})
  public password: string;

  @Column('simple-array')
  public ban_list: string[];

  @Column('simple-array')
  public mute_list: string[];
}
 
export default Chat;