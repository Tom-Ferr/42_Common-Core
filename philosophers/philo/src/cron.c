/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cron.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 19:51:42 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/01 09:49:30 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	getusec(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

unsigned int	myTime(void)
{
	return (getusec() - g_begin);
}

void	cron(void)
{
	unsigned int	pre;

	pre = 0;
	while (!g_ok)
		;
	g_begin = getusec();
	while (1)
	{
		usleep(g_unit);
		pre++;
		g_clock = (pre - pre % 10) + g_rest;
	}
}
