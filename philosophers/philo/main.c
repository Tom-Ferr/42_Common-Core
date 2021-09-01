/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 13:01:03 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/01 13:24:12 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grab_fork(t_rout *rt)
{
	pthread_mutex_lock(&g_mutex);
	if (rt->ph[id(ME, rt)].frk && rt->ph[id(RG, rt)].frk)
		hold_fork(rt);
	pthread_mutex_unlock(&g_mutex);
	return (0);
}

void	grab_food(t_rout *rt)
{
	if (g_panic)
	{
		pthread_mutex_unlock(&rt->ph[id(ME, rt)].mutex);
		pthread_mutex_unlock(&rt->ph[id(RG, rt)].mutex);
		return ;
	}
	feed(rt);
	if (g_panic)
	{
		pthread_mutex_unlock(&rt->ph[id(ME, rt)].mutex);
		pthread_mutex_unlock(&rt->ph[id(RG, rt)].mutex);
		pthread_mutex_unlock(&rt->ph[id(ME, rt)].spaguetti);
		return ;
	}
	snooze(rt);
	if (g_panic)
	{
		pthread_mutex_unlock(&rt->ph[id(ME, rt)].spaguetti);
		return ;
	}
	printf("%u %d is thinking\n", g_clock, id(ME, rt) + 1);
	rt->ph[id(ME, rt)].ready = RESET;
	rt->ph[id(ME, rt)].meals--;
}

void	monitor(t_rout *rt)
{
	while (rt->ph[id(ME, rt)].meals && g_panic == false)
	{
		pthread_mutex_lock(&rt->ph[id(ME, rt)].spaguetti);
		pthread_mutex_unlock(&rt->ph[id(ME, rt)].spaguetti);
		usleep(10000);
		if (g_clock + g_mod.die > \
			(rt->ph[id(ME, rt)].die + rt->ph[id(ME, rt)].starv))
		{
			printf("%u %d died\n", g_clock + g_mod.die - 9, id(ME, rt) + 1);
			g_panic = true;
			return ;
		}
	}
}

void	symposium(t_rout *rt)
{
	pthread_create(&rt->th, NULL, (void *)&monitor, rt);
	pthread_detach(rt->th);
	g_ok = true;
	rt->ph[id(ME, rt)].starv = getusec();
	if (id(ME, rt) == id(RG, rt))
	{
		rt->ph[id(ME, rt)].starv = g_clock;
		rt->ph[id(ME, rt)].frk = 0;
		printf("%u %d has taken a fork\n", g_clock, id(ME, rt) + 1);
	}
	while (rt->ph[id(ME, rt)].meals && g_panic == false)
	{
		if (rt->ph[id(ME, rt)].frk || rt->ph[id(RG, rt)].frk)
			if (grab_fork(rt) || g_panic)
				break ;
		if (rt->ph[id(ME, rt)].ready > 0)
			grab_food(rt);
	}
}

int	main(int argc, char *argv[])
{
	pthread_t		*th;
	int				i;
	t_info			info;
	t_info			*ph;
	t_rout			*rt;

	i = start(argc, argv, &info);
	if (i)
		return (i);
	pthread_mutex_init(&g_mutex, NULL);
	th = (pthread_t *)malloc((info.phi * 2) * sizeof(pthread_t));
	ph = (t_info *)malloc(info.phi * sizeof(t_info));
	rt = (t_rout *)malloc(info.phi * sizeof(t_rout));
	core(info, th, ph, rt);
	i = RESET;
	while (++i < (int)info.phi)
	{
		pthread_mutex_destroy(&ph[i].mutex);
		pthread_mutex_destroy(&ph[i].spaguetti);
	}
	pthread_mutex_destroy(&g_mutex);
	free(th);
	free(ph);
	free(rt);
	return (0);
}
