/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*   By: nfranco- <nfranco-@student.42.fr>        +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/03 19:38:25 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_tty(void)
{
	if (isatty(STDOUT_FILENO))
	{
		dup2(2, 0);
		dup2(2, 1);
	}
}

void	cmd_spacereverse(char **cmd)
{
	int		i;

	i = 0;
	while ((*cmd)[i])
	{
		if ((*cmd)[i] == -2)
			(*cmd)[i] = ' ';
		else if (ft_iscontained((*cmd)[i], " \t"))
			(*cmd)[i] = -2;
		i++;
	}
}

char	*ft_search_env(char *arg, t_list *env)
{
	char	**sp;
	char	*ret;

	ret = NULL;
	while (env)
	{
		if (!ft_strncmp(env->content, arg,
				ft_strlen_tilchar(env->content, '='))
			&& !ft_strncmp(arg, env->content,
				ft_strlen(arg)))
		{
			sp = ft_split(env->content, '=');
			ret = ft_strdup(sp[1]);
			free_star(sp);
			return (ret);
		}
		env = env->next;
	}
	return (ret);
}

void	sig_handle_child(int signus)
{
	if (signus == SIGINT)
	{
		kill(g_main.id, SIGINT);
		write(1, "\n", 1);
	}
	else if (signus == SIGQUIT)
	{
		kill(g_main.id, SIGQUIT);
		printf("Quit\n");
	}
}

int	ft_strlen_tilchar(char *str, char c)
{
	int	i;

	i = 0;
	while (*str++ != c)
		i++;
	return (i);
}
