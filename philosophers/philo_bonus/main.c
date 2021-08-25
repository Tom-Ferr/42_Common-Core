/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:31:24 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/23 20:00:03 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	parent(t_info info)
{
	int		i;
	int		val;
	int		ret;

	i = RESET;
	ret = 1;
	usleep(1000);
	sem_post(info.sem[CTL]);
	while (ret > 0)
	{
		ret = waitpid(-1, &val, 0);
		val = WEXITSTATUS(val);
		if (val && ret > 0)
		{
			while (++i < (int)info.phi)
			{
				if (info.id[i] == ret)
					continue ;
				kill(SIGKILL, info.id[i]);
			}
			break ;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_info	info;

	info.i = start(argc, argv, &info);
	if (info.i)
		return (info.i);
	info.id = (int *)malloc(info.phi * sizeof(int));
	sem_action(&info, true);
	info.i = 0;
	while (info.i < (int)info.phi)
	{
		info.id[info.i] = fork();
		if (!info.id[info.i])
		{
			sem_wait(info.sem[CTL]);
			symposium(info.i + 1, info);
		}
		info.i++;
	}
	parent(info);
	sem_action(&info, false);
	free(info.id);
	return (0);
}
