/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jwt-authentication.guard.ts                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:21:54 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:21:56 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { Injectable } from '@nestjs/common';
import { AuthGuard } from '@nestjs/passport';
 
@Injectable()
export class JwtAuthenticationGuard extends AuthGuard('jwt') {}