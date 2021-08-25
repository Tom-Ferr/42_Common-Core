/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 00:20:50 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/25 12:05:39 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define  PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

# define  RESET -1
# define  ME 0
# define  RG 1
# define  LF -1

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
	pthread_mutex_t	mutex;
	pthread_mutex_t	spaguetti;
}					t_info;

typedef struct s_rout
{
	unsigned int	id;
	int				wait;
	t_info			*ph;
}					t_rout;

unsigned int	mini_atoi(char argv[]);
int				start(int argc, char *argv[], t_info *info);
unsigned int	getusec(void);
void			core(t_info info, pthread_t *th, t_info *ph, t_rout *rt);
int				id(int side, t_rout *rt);
void			hold_fork(t_rout *rt);
void			symposium(t_rout *rt);
void			monitor(t_rout *rt);

#endif
