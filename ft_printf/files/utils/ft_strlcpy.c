/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:37:38 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/08 11:56:35 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char *tcsrc;

	tcsrc = (char*)src;
	if (!src)
		return (0);
	if (size)
	{
		while (--size && *tcsrc)
		{
			*dest++ = *tcsrc++;
		}
		*dest = '\0';
	}
	return (ft_strlen(src));
}
