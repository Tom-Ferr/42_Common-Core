/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/10 16:35:07 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handle(int signus)
{
	if (signus == SIGINT)
	{
		write(1, "\n", 1);
		newline(PROMPT);
	}
}

void	init_term(bool mode)
{
	struct termios	term;

	check_tty();
	if (tcgetattr(STDIN_FILENO, &term) != 0)
	{
		printf("tcgetattr() Error: %s\n", strerror(errno));
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
		printf("tcgetattr() Error: %s\n", strerror(errno));
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
	write(1, PROMPT, ft_strlen(PROMPT));
	write(1, CURSOR_SAVE, 3);
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
		printf("Scripts are not required by the PDF in %s :)\n", argv[0]);
		return (0);
	}
	argc--;
	argv = 0;
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
