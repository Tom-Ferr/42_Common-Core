/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:11:53 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/15 10:45:53 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		convert(int n, int fd)
{
	long	dex;
	int		nl;

	nl = n;
	dex = 10;
	while (nl >= dex)
	{
		while (nl >= dex)
			nl /= 10;
		nl %= 10;
		nl += 48;
		ft_putchar_fd(nl, fd);
		dex *= 10;
		nl = n;
	}
	nl %= 10;
	nl += 48;
	ft_putchar_fd(nl, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	int nl;

	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	nl = n;
	while (nl > 10 || nl < -10)
		nl /= 10;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	convert(n, fd);
}
