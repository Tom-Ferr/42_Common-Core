/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 01:23:33 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/08 12:49:21 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		convert(const char *str, char is_neg, size_t index)
{
	int	ret;
	int	i;
	int	size;

	size = 10;
	ret = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		i = (int)(str[index] - '0');
		if (is_neg == '-' && i)
			i *= -1;
		ret = i + (ret * 10);
		index++;
		if (!size--)
		{
			if (is_neg == '-')
				return (0);
			return (-1);
		}
	}
	return (ret);
}

int				ft_atoi(const char *str)
{
	int			ret;
	char		is_neg;
	size_t		i;

	ret = 0;
	is_neg = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		is_neg = str[i];
		i++;
	}
	ret = convert(str, is_neg, i);
	return (ret);
}
