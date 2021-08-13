/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symposium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:39:42 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/13 12:39:52 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	grab_fork(int ph, t_info *info)
{
	sem_wait(info->sem[CTL]);
	sem_wait(info->sem[FRK]);
	sem_wait(info->sem[DIE]);
	printf("%u %d has taken a fork\n", getusec() / 1000, ph);
	sem_post(info->sem[DIE]);
	sem_wait(info->sem[FRK]);
	sem_wait(info->sem[DIE]);
	printf("%u %d has taken a fork\n", getusec() / 1000, ph);
	sem_post(info->sem[DIE]);
	sem_post(info->sem[CTL]);
	info->ready += 2;
	return (0);
}

void	grab_food(int ph, t_info *info)
{
	sem_wait(info->sem[DIE]);
	printf("%u %d is eating\n", getusec() / 1000, ph);
	sem_post(info->sem[DIE]);
	usleep(info->eat);
	info->starv = getusec();
	sem_post(info->sem[FRK]);
	sem_post(info->sem[FRK]);
	sem_wait(info->sem[DIE]);
	printf("%u %d is sleeping\n", getusec() / 1000, ph);
	sem_post(info->sem[DIE]);
	usleep(info->sleep);
	sem_wait(info->sem[DIE]);
	printf("%u %d is thinking\n", getusec() / 1000, ph);
	sem_post(info->sem[DIE]);
	info->ready = RESET;
	info->meals--;
}

void	monitor(t_info *info)
{
	while (info->meals)
	{
		usleep(100);
		if (info->die < (getusec() - info->starv))
		{
			sem_wait(info->sem[DIE]);
			printf("%u %d died\n", getusec() / 1000, info->i + 1);
			sem_action(info, false);
			free(info->id);
			exit(1);
		}
	}
}

void	symposium(int ph, t_info info)
{
	pthread_t	th;

	info.starv = getusec();
	pthread_create(&th, NULL, (void *)&monitor, &info);
	pthread_detach(th);
	while (info.meals)
	{
		grab_fork(ph, &info);
		if (info.ready > 0)
			grab_food(ph, &info);
	}
	sem_action(&info, false);
	free(info.id);
	exit(0);
}
