/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:07:31 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/01 10:08:10 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	hold_fork(t_rout *rt)
{
	pthread_mutex_unlock(&g_mutex);
	pthread_mutex_lock(&rt->ph[id(ME, rt)].mutex);
	pthread_mutex_lock(&rt->ph[id(RG, rt)].mutex);
	rt->ph[id(ME, rt)].starv = g_clock;
	rt->ph[id(ME, rt)].frk = 0;
	rt->ph[id(RG, rt)].frk = 0;
	if (g_panic)
	{
		pthread_mutex_unlock(&rt->ph[id(ME, rt)].mutex);
		pthread_mutex_unlock(&rt->ph[id(RG, rt)].mutex);
		pthread_mutex_unlock(&g_mutex);
		return ;
	}
	printf("%u %d has taken a fork\n", g_clock, id(ME, rt) + 1);
	if (id(ME, rt) == id(RG, rt))
		return ;
	printf("%u %d has taken a fork\n", g_clock, id(ME, rt) + 1);
	rt->ph[id(ME, rt)].ready += 2;
}

void	snooze(t_rout *rt)
{
	unsigned int	start;

	start = g_clock;
	printf("%u %d is sleeping\n", g_clock, id(ME, rt) + 1);
	pthread_mutex_unlock(&rt->ph[id(ME, rt)].mutex);
	pthread_mutex_unlock(&rt->ph[id(RG, rt)].mutex);
	pthread_mutex_unlock(&rt->ph[id(ME, rt)].spaguetti);
	while (g_clock + g_mod.sleep < (start + rt->ph[id(ME, rt)].sleep))
		;
	pthread_mutex_lock(&g_mutex);
	if (g_clock > g_prev)
	{
		g_rest += g_mod.sleep;
		g_prev = g_clock + g_mod.sleep;
		usleep(1000);
	}
	pthread_mutex_unlock(&g_mutex);
}

void	feed(t_rout *rt)
{
	pthread_mutex_lock(&rt->ph[id(ME, rt)].spaguetti);
	printf("%u %d is eating\n", g_clock, id(ME, rt) + 1);
	while (g_clock + g_mod.eat < \
		(rt->ph[id(ME, rt)].starv + rt->ph[id(ME, rt)].eat))
	{
		rt->ph[id(ME, rt)].frk = 1;
		rt->ph[id(RG, rt)].frk = 1;
	}
	pthread_mutex_lock(&g_mutex);
	if (g_clock > g_prev)
	{
		g_rest += g_mod.eat;
		g_prev = g_clock + g_mod.eat;
		usleep(1000);
	}
	pthread_mutex_unlock(&g_mutex);
}
