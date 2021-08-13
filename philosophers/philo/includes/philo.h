/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 00:20:50 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/13 12:48:22 by tde-cama         ###   ########.fr       */
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
}					t_info;

typedef struct s_rout
{
	unsigned int	id;
	t_info			*ph;
}					t_rout;

int				start(int argc, char *argv[], t_info *info);
unsigned int	getusec(void);
void			core(t_info info, pthread_t *th, t_info *ph, t_rout *rt);
void			symposium(t_rout *rt);

#endif
