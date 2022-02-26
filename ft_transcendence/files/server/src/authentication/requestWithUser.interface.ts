import { Request } from 'express';
import User from '../users/user.entity';
 
export interface RequestWithUser extends Request {
  user: User;
}
 