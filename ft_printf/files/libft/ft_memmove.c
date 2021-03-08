/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:45:21 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/14 16:42:27 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *tcdest;
	char *tcsrc;

	tcdest = (char*)dest;
	tcsrc = (char*)src;
	if (!dest && !src)
		return (0);
	if (tcdest > tcsrc)
	{
		while (n--)
			*(tcdest + n) = *(tcsrc + n);
	}
	else
	{
		while (n--)
			*(tcdest++) = *(tcsrc++);
	}
	return (dest);
}
