/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:39:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/08 12:50:57 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	void	write_symbol(long z, bool a)
{
	char c;

	c = 'a';
	if (a)
		c = 'A';
	if (z >= 10)
		z = (z % 10) + c;
	else
		z = z + '0';
	write(1, &z, 1);
}

void			ft_puthex(long d, bool a)
{
	long n;
	long m;

	n = d / 16;
	m = d % 16;
	if (n < 16)
	{
		write_symbol(n, a);
		write_symbol(m, a);
	}
	else
	{
		ft_puthex(n, a);
		write_symbol(m, a);
	}
}
