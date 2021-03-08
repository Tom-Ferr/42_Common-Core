/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:16:45 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/14 16:13:45 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nblock, size_t size)
{
	void	*ptr;
	size_t	sizeblock;

	sizeblock = nblock * size;
	ptr = malloc(sizeblock);
	if (!ptr)
		return (0);
	ft_bzero(ptr, sizeblock);
	return (ptr);
}
