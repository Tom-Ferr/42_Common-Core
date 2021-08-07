/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 13:01:03 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/07 19:13:50 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grab_fork(t_rout *rt)
{
	pthread_mutex_lock(&g_mutex_l);
	if (rt->ph[rt->id].frk)
	{
		rt->ph[rt->id].frk = 0;
		printf("%u %d has taken a fork\n", getusec() / 1000, rt->id + 1);
		rt->ph[rt->id].ready++;
	}
	pthread_mutex_unlock(&g_mutex_l);
	if (rt->ph[rt->id].die < (getusec() - rt->ph[rt->id].starv))
		return (1);
	pthread_mutex_lock(&g_mutex_r);
	if (rt->ph[(rt->id + 1) % rt->ph[rt->id].phi].frk)
	{
		rt->ph[(rt->id + 1) % rt->ph[rt->id].phi].frk = 0;
		printf("%u %d has taken a fork\n", getusec() / 1000, rt->id + 1);
		rt->ph[rt->id].ready++;
	}
	pthread_mutex_unlock(&g_mutex_r);
	return (0);
}

void	grab_food(t_rout *rt)
{
	if (g_panic)
		return ;
	printf("%u %d is eating\n", getusec() / 1000, rt->id + 1);
	usleep(rt->ph[rt->id].eat);
	rt->ph[rt->id].starv = getusec();
	if (g_panic)
		return ;
	pthread_mutex_lock(&g_mutex_l);
	pthread_mutex_lock(&g_mutex_r);
	rt->ph[rt->id].frk = 1;
	rt->ph[(rt->id + 1) % rt->ph[rt->id].phi].frk = 1;
	printf("%u %d is sleeping\n", getusec() / 1000, rt->id + 1);
	pthread_mutex_unlock(&g_mutex_l);
	pthread_mutex_unlock(&g_mutex_r);
	usleep(rt->ph[rt->id].sleep);
	if (g_panic)
		return ;
	printf("%u %d is thinking\n", getusec() / 1000, rt->id + 1);
	rt->ph[rt->id].ready = RESET;
	rt->ph[rt->id].meals--;
}

void	routine(t_rout *rt)
{
	rt->ph[rt->id].starv = getusec();
	while ((rt->ph[rt->id].die < (getusec() - rt->ph[rt->id].starv)
			|| rt->ph[rt->id].meals) && g_panic == false)
	{
		if (rt->ph[rt->id].frk || rt->ph[(rt->id + 1) % rt->ph[rt->id].phi].frk)
			if (grab_fork(rt) || g_panic)
				break ;
		if (rt->ph[rt->id].die < (getusec() - rt->ph[rt->id].starv) || g_panic)
			break ;
		if (rt->ph[rt->id].ready > 0)
			grab_food(rt);
	}
	if (rt->ph[rt->id].meals && g_panic == false)
	{
		g_panic = true;
		printf("%u %d died\n", getusec() / 1000, rt->id + 1);
	}
}

void	core(t_info info, pthread_t *th, t_info *ph, t_rout *rt)
{
	int	i;

	i = RESET;
	while (++i < (int)info.phi)
		ph[i] = info;
	i = RESET;
	while (++i < (int)info.phi)
	{
		rt[i].ph = ph;
		rt[i].id = i;
		pthread_create(&th[i], NULL, (void *)&routine, &rt[i]);
	}
	i = RESET;
	while (++i < (int)info.phi)
		pthread_join(th[i], NULL);
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
	pthread_mutex_init(&g_mutex_l, NULL);
	pthread_mutex_init(&g_mutex_r, NULL);
	th = (pthread_t *)malloc(info.phi * sizeof(pthread_t));
	ph = (t_info *)malloc(info.phi * sizeof(t_info));
	rt = (t_rout *)malloc(info.phi * sizeof(t_rout));
	core(info, th, ph, rt);
	free(th);
	free(ph);
	free(rt);
	pthread_mutex_destroy(&g_mutex_l);
	pthread_mutex_destroy(&g_mutex_r);
	return (0);
}
