/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 13:01:03 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/25 12:05:14 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool							g_panic;
static pthread_mutex_t				g_mutex;

int	grab_fork(t_rout *rt)
{
	pthread_mutex_lock(&g_mutex);
	if (rt->ph[id(ME, rt)].frk && rt->ph[id(RG, rt)].frk)
		hold_fork(rt);
	else if (rt->ph[id(RG, rt)].frk == 0 && rt->ph[id(LF, rt)].frk == 0)
		hold_fork(rt);
	pthread_mutex_unlock(&g_mutex);
	return (0);
}

void	grab_food(t_rout *rt)
{
	if (g_panic)
		return ;
	pthread_mutex_lock(&rt->ph[id(ME, rt)].spaguetti);
	printf("%u %d is eating\n", getusec() / 1000, id(ME, rt) + 1);
	rt->ph[id(ME, rt)].starv = getusec();
	usleep(rt->ph[id(ME, rt)].eat);
	rt->ph[id(ME, rt)].frk = 1;
	rt->ph[id(RG, rt)].frk = 1;
	pthread_mutex_unlock(&rt->ph[id(ME, rt)].mutex);
	pthread_mutex_unlock(&rt->ph[id(RG, rt)].mutex);
	pthread_mutex_unlock(&rt->ph[id(ME, rt)].spaguetti);
	if (g_panic)
		return ;
	printf("%u %d is sleeping\n", getusec() / 1000, id(ME, rt) + 1);
	usleep(rt->ph[id(ME, rt)].sleep);
	if (g_panic)
		return ;
	printf("%u %d is thinking\n", getusec() / 1000, id(ME, rt) + 1);
	rt->ph[id(ME, rt)].ready = RESET;
	rt->ph[id(ME, rt)].meals--;
}

void	symposium(t_rout *rt)
{
	rt->ph[id(ME, rt)].starv = getusec();
	while (rt->ph[id(ME, rt)].meals && g_panic == false)
	{
		if (rt->ph[id(ME, rt)].frk || rt->ph[id(RG, rt)].frk)
			if (grab_fork(rt) || g_panic)
				break ;
		if (rt->ph[id(ME, rt)].ready > 0)
			grab_food(rt);
	}
}

void	monitor(t_rout *rt)
{
	while (rt->ph[id(ME, rt)].meals && g_panic == false)
	{
		pthread_mutex_lock(&rt->ph[id(ME, rt)].spaguetti);
		pthread_mutex_unlock(&rt->ph[id(ME, rt)].spaguetti);
		if (rt->ph[id(ME, rt)].die < (getusec() - rt->ph[id(ME, rt)].starv))
		{
			pthread_mutex_lock(&rt->ph[id(ME, rt)].spaguetti);
			pthread_mutex_unlock(&rt->ph[id(ME, rt)].spaguetti);
			usleep(5000);
			if (rt->ph[id(ME, rt)].die >= (getusec() - rt->ph[id(ME, rt)].starv)
				|| g_panic)
				continue ;
			g_panic = true;
			printf("%u %d died\n", getusec() / 1000, id(ME, rt) + 1);
			return ;
		}
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
