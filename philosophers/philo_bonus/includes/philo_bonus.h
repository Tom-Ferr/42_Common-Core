/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:41:36 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/23 15:24:14 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define  PHILO_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <semaphore.h>

# define  RESET -1
# define  FRK 0
# define  CTL 1
# define  DIE 2
# define  EAT 3

typedef struct s_info
{
	unsigned int	phi;
	unsigned int	die;
	unsigned int	eat;
	unsigned int	sleep;
	unsigned int	starv;
	int				meals;
	int				frk;
	int				ready;
	int				i;
	int				*id;
	sem_t			*sem[4];

}					t_info;

int				start(int argc, char *argv[], t_info *info);
unsigned int	getusec(void);
void			sem_action(t_info *info, bool mode);
void			symposium(int ph, t_info info);

#endif
