/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:29:01 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/13 14:13:54 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_term()
{
	struct termios term;

	if (tcgetattr(STDIN_FILENO, &term) != 0)
	{
		perror("tcgetatt() Error");
		exit(1);
	}
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) != 0)
	{
		perror("tcsetattr() Error");
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	char	input[4];
	char	*live;
	int		fd_hist;
	t_list	*buff;
	size_t	i;
	int	j;

	i = 0;
	j = 0;
	if (argc > 1)
	{
		printf("Please, no arguments after %s\n", argv[0]);
		return (0);
	}
	fd_hist = open(".history.log", O_APPEND | O_CREAT | O_RDWR, S_IRWXU);
	if (fd_hist < 0)
		perror("Error");
	init_term();
	live = ft_calloc(800 + 1, sizeof(char));
	write(1, "minishell > ", 12);
	buff = NULL;
	get_history(live, &buff);
	while (1)
	{
		signal(SIGINT, SIG_IGN);
		read(0, input, 3);
		if (input[0] > 31)
			str_update(live, input[0], &i);
		else if (!ft_strcmp(input, UP))
		{
			if (j < ft_lstsize(buff) - 1)
				j++;
			load_history(&live, buff, j);
			i = ft_strlen(live);
		}
		else if (!ft_strcmp(input, DOWN))
		{
			if (j)
				j--;
			load_history(&live, buff, j);
			i = ft_strlen(live);
		}
		else if (!ft_strcmp(input, RIGHT) && i < ft_strlen(live))
		{
			write(1, RIGHT, 3);
			i++;
		}
		else if (!ft_strcmp(input, LEFT) && i)
		{
			write(1, LEFT, 3);
			i--;
		}
		else if (input[0] == CTRL_D && !live[0])
			break ;
		else if (input[0] == CTRL_C)
		{
			free_lst(&buff);
			live = ft_calloc(800 + 1, sizeof(char));
			get_history(live, &buff);
			write(1, "\nminishell > ", 13);
			i = 0;
			j = 0;
		}
		else if (input[0] == CTRL_L)
		{
			write(1, CLEAR_SCREEN, 4);
			write(1, CURSOR_HOME, 3);
			str_update(live, input[0], &i);
		}
		else if (input[0] == '\n' )
		{
			if (live[0])
			{
				write(fd_hist, live, ft_strlen(live));
				write(fd_hist, "\n", 1);
			}
			free_lst(&buff);
			live = ft_calloc(800 + 1, sizeof(char));
			get_history(live, &buff);
			write(1, "\nminishell > ", 13);
			i = 0;
			j = 0;
		}
	}
	close(fd_hist);
	printf("exit\n");
	return (0);
}
