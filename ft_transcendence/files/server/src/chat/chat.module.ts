import { Module } from '@nestjs/common';
import { ChatGateway } from './chat.gateway';
import { AuthenticationModule } from '../authentication/authentication.module';
import { ChatService } from './chat.service';
import { TypeOrmModule } from '@nestjs/typeorm';
import Chat from './chat.entity';
import { ChatController } from './chat.controller';

@Module({
  imports: [
    AuthenticationModule,
    TypeOrmModule.forFeature([Chat]),
  ],
  controllers: [ChatController],
  providers: [ChatGateway, ChatService],
})
export class ChatModule {}
