/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:43:20 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/14 16:42:27 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tcdest;
	unsigned char	*tcsrc;
	unsigned char	tcc;

	tcdest = (unsigned char*)dest;
	tcsrc = (unsigned char*)src;
	tcc = (unsigned char)c;
	while (n--)
	{
		*(tcdest++) = *(tcsrc++);
		dest++;
		if (*(tcsrc - 1) == tcc)
			return (dest);
	}
	return (0);
}
