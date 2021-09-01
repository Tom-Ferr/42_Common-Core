/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 00:20:50 by tde-cama          #+#    #+#             */
/*   Updated: 2021/09/01 10:11:42 by tde-cama         ###   ########.fr       */
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

typedef struct s_mod
{
	unsigned int	die;
	unsigned int	eat;
	unsigned int	sleep;
	unsigned int	frk;
}					t_mod;

typedef struct s_rout
{
	unsigned int	id;
	t_info			*ph;
	pthread_t		th;
}					t_rout;

unsigned int	g_clock;
unsigned int	g_begin;
unsigned int	g_rest;
unsigned int	g_prev;
unsigned int	g_unit;
bool			g_panic;
bool			g_ok;
pthread_mutex_t	g_mutex;
t_mod			g_mod;

unsigned int	mini_atoi(char argv[]);
int				start(int argc, char *argv[], t_info *info);
unsigned int	getusec(void);
void			core(t_info info, pthread_t *th, t_info *ph, t_rout *rt);
void			create_join(t_info info, pthread_t *th, t_info *ph, t_rout *rt);
int				id(int side, t_rout *rt);
void			hold_fork(t_rout *rt);
void			symposium(t_rout *rt);
void			monitor(t_rout *rt);
unsigned int	myTime(void);
void			grab_food(t_rout *rt);
void			snooze(t_rout *rt);
void			cron(void);
void			feed(t_rout *rt);
void			mod(t_info *info);

#endif
