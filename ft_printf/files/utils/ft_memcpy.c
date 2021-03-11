/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:37:46 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/08 12:50:40 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tcdest;
	const char	*tcsrc;

	tcdest = (char*)dest;
	tcsrc = (const char*)src;
	if (!dest && !src)
		return (0);
	while (n--)
		*(tcdest++) = *(tcsrc++);
	return (dest);
}
