#ifndef PHILO_BONUS_H
# define  PHILO_BONUS_H

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

struct timeval	g_t;
pthread_mutex_t	g_mutex_r;
pthread_mutex_t	g_mutex_l;
bool			g_panic;

int				start(int argc, char *argv[], t_info *info);
unsigned int	getusec(void);

#endif
