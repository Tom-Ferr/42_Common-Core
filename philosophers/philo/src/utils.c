/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 13:03:52 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/28 15:08:26 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

unsigned int	mini_atoi(char argv[])
{
	int	pow;
	int	i;
	int	ret;

	pow = 1;
	ret = 0;
	i = ft_strlen(argv);
	while (--i >= 0)
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (0);
		ret = ret + (argv[i] - '0') * pow;
		pow *= 10;
	}
	return (ret);
}

void	mod(t_info *info)
{
	g_mod.eat = info->eat % 10;
	g_mod.sleep = info->sleep % 10;
	g_mod.die = info->die % 10;
}

int	id(int side, t_rout *rt)
{
	return ((rt->id + side) % rt->ph[0].phi);
}
