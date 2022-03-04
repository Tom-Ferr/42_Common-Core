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
}
 
export default User;