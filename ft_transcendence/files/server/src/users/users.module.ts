import { Module } from '@nestjs/common';
import { UsersService } from './users.service';
import { TypeOrmModule } from '@nestjs/typeorm';
import User from './user.entity';
import { AvatarModule } from 'src/avatar/avatar.module';
import AvatarService from 'src/avatar/avatar.service';
 
@Module({
  imports: [
    AvatarModule,
    TypeOrmModule.forFeature([User]),
  ],
  providers: [UsersService],
  exports: [UsersService]
})
export class UsersModule {}