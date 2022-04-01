import { Module } from '@nestjs/common';
import { TypeOrmModule } from '@nestjs/typeorm';
import { DatabaseController } from './avatar.controller';
import Avatar from './avatar.entity';
import AvatarService from './avatar.service';
 
@Module({
  imports: [TypeOrmModule.forFeature([Avatar])],
  controllers: [DatabaseController],
  providers: [AvatarService],
  exports: [AvatarService]
})
export class AvatarModule {}