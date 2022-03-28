import { Column, Entity, PrimaryGeneratedColumn } from 'typeorm';
 
@Entity()
class User {
  @PrimaryGeneratedColumn()
  public id: number;

  @Column({ default: false })
  public isTwoFactorAuthenticationEnabled: boolean;
 
  @Column({ nullable: true })
  public twoFactorAuthenticationSecret?: string;
 
  @Column({ unique: true })
  public email: string;
 
  @Column({ unique: true })
  public name: string;
 
  @Column()
  public password: string;

  @Column({ nullable: true })
  public sessionID: string;

  @Column({ type: "jsonb"})
  public mail: {
    from: string;
    message: string;
  }[]

  @Column('simple-array')
  public block_list: string[]
}
 
export default User;