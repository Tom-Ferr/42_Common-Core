/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   localAuthentication.guard.ts                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:22:26 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:22:27 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Injectable } from '@nestjs/common';
import { AuthGuard } from '@nestjs/passport';
 
@Injectable()
export class LocalAuthenticationGuard extends AuthGuard('local') {}