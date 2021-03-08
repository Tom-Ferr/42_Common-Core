/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:04:47 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/16 11:42:49 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char *tcstr;

	tcstr = (char*)str;
	while (n--)
	{
		if (*(tcstr++) == c % 256)
			return (tcstr - 1);
	}
	return (0);
}
