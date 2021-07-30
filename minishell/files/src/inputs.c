/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:37:31 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/30 16:34:29 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	clear(char *prompt)
{
	write(1, CLEAR_SCREEN, 4);
	write(1, CURSOR_HOME, 3);
	write(1, prompt, ft_strlen(prompt));
	write(1, "\e[s", 3);
	str_update(g_main.live, g_main.input[0], &g_main.i);
}

void 	newline(char *prompt)
{
	free_lst(&g_main.buff);
	g_main.live = ft_calloc(800 + 1, sizeof(char));
	get_history();
	write(1, prompt, ft_strlen(prompt));
	write(1, "\e[s", 3);
	g_main.i = 0;
	g_main.j = 0;
}

void	envarray_util(t_list *envp, int *i)
{
	while (envp)
	{
		if (envp->visible)
			(*i) += 1;
		envp = envp->next;
	}
}

char	**ft_envarray(t_list *envp)
{
	char	**env_array;
	t_list	*zeroth;
	int		i;

	i = 0;
	zeroth = envp;
	envarray_util(envp, &i);
	env_array = (char **)malloc(i * sizeof(char *));
	i = 0;
	envp = zeroth;
	while (envp)
	{
		if (envp->visible)
		{
			env_array[i] = ft_strdup(envp->content);
			i++;
		}
		envp = envp->next;
	}
	env_array[i] = NULL;
	envp = zeroth;
	return (env_array);
}

void	run_util(char **visible_env)
{
	if (g_main.id == 0)
	{
		init_term(true);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		ft_exec(g_main.parse.pipe, g_main.parse.cmd, visible_env);
	}
	else
	{
		signal(SIGINT, &sig_handle_child);
		signal(SIGQUIT, &sig_handle_child);
		wait(&g_main.exitval);
		init_term(false);
		g_main.exitval = WEXITSTATUS(g_main.exitval);
	}
}

void	ft_run(void)
{
	char	**visible_env;

	g_main.parse.cmd = NULL;
	visible_env = ft_envarray(g_main.env);
	if (ft_parsing(g_main.live) == 258)
	{
		write(2, "syntax error near token\n", 24);
		g_main.exitval = 258;
	}
	if (g_main.parse.cmd)
		ft_otherbuiltins(g_main.parse.cmd);
	if (g_main.parse.cmd && g_main.parse.cmd[0])
	{
		g_main.id = fork();
		run_util(visible_env);
	}
	free_star(visible_env);
	if (g_main.parse.cmd)
		free_star(g_main.parse.cmd);
	if (g_main.parse.input.file)
		free(g_main.parse.input.file);
	if (g_main.parse.output.file)
		free(g_main.parse.output.file);
}

void	check_input(void)
{
	if (g_main.input[0] > 31 || g_main.input[0] == '\t')
		str_update(g_main.live, g_main.input[0], &(g_main.i));
	else if (g_main.input[0] == '\e' && g_main.input[1] == '[')
		arrow_keys();
	else if (g_main.input[0] == CTRL_L)
		clear("minishell > ");
	else if (g_main.input[0] == '\n')
	{
		write(1, "\n", 1);
		if (g_main.live[0])
		{
			save_history();
			ft_run();
		}
		newline("minishell > ");
	}
}
