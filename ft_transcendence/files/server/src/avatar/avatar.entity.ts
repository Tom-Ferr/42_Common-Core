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