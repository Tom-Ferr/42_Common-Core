/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:51:37 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/17 21:45:15 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*tdest;
	size_t	dlen;
	char	*tcsrc;

	tcsrc = (char*)src;
	dlen = ft_strlen(dest);
	tdest = dest + dlen;
	if (size <= dlen)
		return (ft_strlen(src) + size);
	while (*tcsrc && (--size) - dlen)
		*(tdest++) = *(tcsrc++);
	*tdest = '\0';
	return (ft_strlen(src) + dlen);
}
