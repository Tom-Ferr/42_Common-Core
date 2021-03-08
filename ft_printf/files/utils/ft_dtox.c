/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:39:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/08 10:15:18 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*write_symbol(long z, bool a)
{
	char c;

	c = 'a';
	if (a)
		c = 'A';
	if (z >= 10)
		z = (z % 10) + c;
	else
		z = z + '0';
	return (ft_make_str(1,z));
}

char			*ft_dtox(long d, bool a)
{
	long n;
	long m;
	char *ptr;

	n = d / 16;
	m = d % 16;
	if (n < 16)
		ptr = ft_strjoin_free(write_symbol(n, a), write_symbol(m, a));
	else
	{
		ptr = ft_dtox(n, a);
		ptr = ft_strjoin_free(ptr, write_symbol(m, a));
	}
	return (ptr);
}
