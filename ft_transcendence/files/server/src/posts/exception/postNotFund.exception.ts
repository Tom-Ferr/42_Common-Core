/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postNotFund.exception.ts                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:25:18 by tde-cama          #+#    #+#             */
/*   Updated: 2022/04/01 19:25:19 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import { NotFoundException } from '@nestjs/common';
 
class PostNotFoundException extends NotFoundException {
  constructor(postId: number) {
    super(`Post with id ${postId} not found`);
  }
}
export default PostNotFoundException