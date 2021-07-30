/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:29:01 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/30 13:31:54 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handle(int signus)
{
	if (signus == SIGINT)
	{
		write(1, "\n", 1);
		newline("minishell > ");
	}
}

void	init_term(bool mode)
{
	struct termios	term;

	if (tcgetattr(STDIN_FILENO, &term) != 0)
	{
		perror("tcgetatt() Error");
		exit(1);
	}
	if (!mode)
	{
		term.c_lflag &= ~ICANON;
		term.c_lflag &= ~ECHO;
	}
	else
	{
		term.c_lflag |= ICANON;
		term.c_lflag |= ECHO;
	}
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) != 0)
	{
		perror("tcsetattr() Error");
		exit(1);
	}
}

void	start(void)
{
	g_main.i = 0;
	g_main.j = 0;
	g_main.fd_hist = open_history("/tmp/.history.log");
	g_main.live = ft_calloc(800 + 1, sizeof(char));
	g_main.buff = NULL;
	g_main.env->visible = 1;
	init_term(false);
	get_history();
	write(1, "minishell > ", 12);
	write(1, "\e[s", 3);
}

void	loop(void)
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

int	main(int argc, char *argv[], char *env[])
{
	if (argc > 1)
	{
		printf("Please, no arguments after %s\n", argv[0]);
		return (0);
	}
	copy_env(env);
	start();
	loop();
	free_lst(&g_main.buff);
	free_lst(&g_main.env);
	close(g_main.fd_hist);
	printf("exit\n");
	init_term(true);
	return (0);
}
