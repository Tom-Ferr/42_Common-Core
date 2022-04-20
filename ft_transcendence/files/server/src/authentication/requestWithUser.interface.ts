/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requestWithUser.interface.ts                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:22:35 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:22:35 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Request } from 'express';
import User from '../users/user.entity';
 
export interface RequestWithUser extends Request {
  user: User;
}
 