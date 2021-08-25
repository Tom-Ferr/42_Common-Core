/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:15:55 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/25 12:05:51 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start(int argc, char *argv[], t_info *info)
{
	if (argc < 5 || argc > 6)
		return (write(2, ":( 4 Arguments needed. A 5th is optional\n", 42), 10);
	info->phi = mini_atoi(argv[1]);
	if (!info->phi)
		return (write(2, ":( Wrong Input at 1st Argument\n", 30), 1);
	info->die = mini_atoi(argv[2]) * 1000;
	if (!info->die)
		return (write(2, ":( Wrong Input at 2nd Argument\n", 30), 2);
	info->eat = mini_atoi(argv[3]) * 1000;
	if (!info->eat)
		return (write(2, ":( Wrong Input at 3rd Argument\n", 30), 3);
	info->sleep = mini_atoi(argv[4]) * 1000;
	if (!info->sleep)
		return (write(2, ":( Wrong Input at 4th Argument\n", 30), 4);
	info->meals = -1;
	if (argc > 5)
		info->meals = mini_atoi(argv[5]);
	if (!info->meals)
		return (write(2, ":( Wrong Input at 5th Argument\n", 30), 5);
	info->frk = 1;
	info->ready = RESET;
	return (0);
}

void	core(t_info info, pthread_t *th, t_info *ph, t_rout *rt)
{
	int	i;

	i = RESET;
	while (++i < (int)info.phi)
	{
		ph[i] = info;
		pthread_mutex_init(&ph[i].mutex, NULL);
		pthread_mutex_init(&ph[i].spaguetti, NULL);
	}
	i = RESET;
	while (++i < (int)info.phi)
	{
		rt[i].ph = ph;
		rt[i].id = i + info.phi;
		pthread_create(&th[i], NULL, (void *)&symposium, &rt[i]);
		pthread_create(&th[i + info.phi], NULL, (void *)&monitor, &rt[i]);
		pthread_detach(th[i + info.phi]);
	}
	i = RESET;
	while (++i < (int)info.phi)
		pthread_join(th[i], NULL);
}

void	hold_fork(t_rout *rt)
{
	pthread_mutex_lock(&rt->ph[id(ME, rt)].mutex);
	rt->ph[id(ME, rt)].frk = 0;
	printf("%u %d has taken a fork\n", getusec() / 1000, id(ME, rt) + 1);
	if (id(ME, rt) == id(RG, rt))
		return ;
	pthread_mutex_lock(&rt->ph[id(RG, rt)].mutex);
	rt->ph[id(RG, rt)].frk = 0;
	printf("%u %d has taken a fork\n", getusec() / 1000, id(ME, rt) + 1);
	rt->ph[id(ME, rt)].ready += 2;
}
