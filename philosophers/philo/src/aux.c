/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:15:55 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/01 10:38:20 by tde-cama         ###   ########.fr       */
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
	info->die = mini_atoi(argv[2]);
	if (!info->die)
		return (write(2, ":( Wrong Input at 2nd Argument\n", 30), 2);
	info->eat = mini_atoi(argv[3]);
	if (!info->eat)
		return (write(2, ":( Wrong Input at 3rd Argument\n", 30), 3);
	info->sleep = mini_atoi(argv[4]);
	if (!info->sleep)
		return (write(2, ":( Wrong Input at 4th Argument\n", 30), 4);
	info->meals = -1;
	if (argc > 5)
		info->meals = mini_atoi(argv[5]);
	if (!info->meals)
		return (write(2, ":( Wrong Input at 5th Argument\n", 30), 5);
	info->frk = 1;
	info->ready = RESET;
	mod(info);
	g_rest = 0;
	g_prev = 0;
	return (0);
}

void	core(t_info info, pthread_t *th, t_info *ph, t_rout *rt)
{
	pthread_t		cr;

	g_ok = false;
	if (info.phi >= 100)
		g_unit = 5000;
	else if (info.phi > 20)
		g_unit = 3000;
	else
		g_unit = 1000;
	pthread_create(&cr, NULL, (void *)&cron, NULL);
	pthread_detach(cr);
	create_join(info, th, ph, rt);
}

void	create_join(t_info info, pthread_t *th, t_info *ph, t_rout *rt)
{
	int				i;

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
	}
	i = RESET;
	while (++i < (int)info.phi)
		pthread_create(&th[i], NULL, (void *)&symposium, &rt[i]);
	i = RESET;
	while (++i < (int)info.phi)
		pthread_join(th[i], NULL);
}
