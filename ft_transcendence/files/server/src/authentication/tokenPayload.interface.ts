/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenPayload.interface.ts                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:22:38 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:22:39 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

export interface TokenPayload {
    userId: number;
    isSecondFactorAuthenticated?: boolean;
  }