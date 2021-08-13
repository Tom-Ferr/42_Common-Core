/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 13:03:52 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/13 12:35:05 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

static unsigned int	mini_atoi(char argv[])
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

unsigned int	getusec(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000000) + (t.tv_usec));
}

void	sem_action(t_info *info, bool mode)
{
	sem_unlink("fork");
	sem_unlink("control");
	sem_unlink("die");
	if (mode)
	{
		info->sem[FRK] = sem_open("fork", O_CREAT | O_EXCL, 0644, info->phi);
		info->sem[CTL] = sem_open("control", O_CREAT | O_EXCL, 0644, 1);
		info->sem[DIE] = sem_open("die", O_CREAT | O_EXCL, 0644, 1);
	}
	else
	{
		sem_close(info->sem[FRK]);
		sem_close(info->sem[CTL]);
		sem_close(info->sem[DIE]);
	}
}
