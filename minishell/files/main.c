/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:29:01 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/13 22:28:17 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handle(int signus)
{
	if (signus == SIGINT)
		newline();
}

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

void	start()
{
	g_main.i = 0;
	g_main.j = 0;
	g_main.fd_hist = open_history();
	g_main.live = ft_calloc(800 + 1, sizeof(char));
	g_main.buff = NULL;
	init_term();
	get_history();
	write(1, "minishell > ", 12);
}

void	loop()
{
	while (1)
	{
		signal(SIGINT, &sig_handle);
		signal(SIGQUIT, &sig_handle);
		read(0, g_main.input, 3);
		if (g_main.input[0] == CTRL_D && !g_main.live[0])
			break ;
		else
			check_input();
	}
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		printf("Please, no arguments after %s\n", argv[0]);
		return (0);
	}
	start();
	loop();
	free_lst(&g_main.buff);
	close(g_main.fd_hist);
	printf("exit\n");
	return (0);
}
