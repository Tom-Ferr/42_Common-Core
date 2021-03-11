/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:24:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/09 14:05:13 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*create_ptr(int n, int len)
{
	char *ptr;
	char *ret;

	if (n < 0)
	{
		ptr = (char *)malloc((len + 2));
		if (!ptr)
			return (0);
		*ptr = '-';
		n *= -1;
		ret = ptr++;
	}
	else
	{
		ptr = (char *)malloc(len + 1);
		if (!ptr)
			return (0);
		ret = ptr;
	}
	return (ret);
}

static char		*convert(char *ptr, int n, int index)
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
		ptr[index] = nl;
		index++;
		dex *= 10;
		nl = n;
	}
	nl %= 10;
	nl += 48;
	ptr[index] = nl;
	index++;
	ptr[index] = '\0';
	return (ptr);
}

char			*ft_itoa(int n)
{
	int		len;
	int		nl;
	int		i;
	char	*ptr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 1;
	nl = n;
	i = 0;
	while (nl >= 10 || nl <= -10)
	{
		nl /= 10;
		len++;
	}
	ptr = create_ptr(n, len);
	if (!ptr)
		return (0);
	if (n < 0)
	{
		ptr[i] = '-';
		n *= -1;
		i++;
	}
	return (convert(ptr, n, i));
}
