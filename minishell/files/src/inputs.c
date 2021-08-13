/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*   By: nfranco- <nfranco-@student.42.fr>        +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/03 19:38:25 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear(char *prompt)
{
	write(1, CLEAR_SCREEN, 4);
	write(1, CURSOR_HOME, 3);
	write(1, prompt, ft_strlen(prompt));
	write(1, CURSOR_SAVE, 3);
	str_update(g_main.live, g_main.input[0], &g_main.i);
}

void	newline(char *prompt)
{
	free_lst(&g_main.buff);
	g_main.live = ft_calloc(800 + 1, sizeof(char));
	get_history();
	write(1, prompt, ft_strlen(prompt));
	write(1, CURSOR_SAVE, 3);
	g_main.i = 0;
	g_main.j = 0;
	g_main.rows_up = 0;
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

void	check_input(void)
{
	if (g_main.input[0] > 31 || g_main.input[0] == '\t')
		str_update(g_main.live, g_main.input[0], &(g_main.i));
	else if (g_main.input[0] == '\e' && g_main.input[1] == '[')
		arrow_keys();
	else if (g_main.input[0] == CTRL_L)
		clear(PROMPT);
	else if (g_main.input[0] == '\n')
	{
		write(1, "\n", 1);
		if (g_main.live[0])
		{
			save_history();
			ft_run();
		}
		newline(PROMPT);
	}
}
