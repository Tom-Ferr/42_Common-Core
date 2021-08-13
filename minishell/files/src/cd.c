/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*   By: nfranco- <nfranco-@student.42.fr>        +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/03 19:38:25 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	oldpwd_update(t_list **env, char **dir)
{
	char	*home;
	char	*old_pwd;

	old_pwd = NULL;
	home = ft_search_env("HOME", *env);
	*dir = ft_strjoin(ft_strdup("OLDPWD="), getcwd(old_pwd, 256), 0);
	if (chdir(home) < 0)
	{
		free(home);
		free(*dir);
		return (1);
	}
	ft_export(1, dir, env);
	free(*dir);
	*dir = ft_strjoin(ft_strdup("PWD="), home, 0);
	return (0);
}

char	*cd_util(int argc, char *argv[], t_list **env, char **dir)
{
	char	*old_pwd;
	char	*pwd;

	pwd = NULL;
	old_pwd = NULL;
	lst_rewind(*env);
	if (argc < 2)
	{
		if (oldpwd_update(env, dir))
			return (NULL);
	}
	else if (argc < 3)
	{
		*dir = ft_strjoin(ft_strdup("OLDPWD="), getcwd(old_pwd, 256), 0);
		if (chdir(argv[1]) < 0)
		{
			free(*dir);
			return (NULL);
		}
		ft_export(1, dir, env);
		free(*dir);
		*dir = ft_strjoin(ft_strdup("PWD="), getcwd(pwd, 256), 0);
	}
	return (*dir);
}

int	ft_cd(int argc, char *argv[], t_list **env)
{
	char	*dir;
	t_list	*zeroth;

	dir = NULL;
	zeroth = *env;
	if (!cd_util(argc, argv, env, &dir))
	{
		errno = ENOENT;
		return (1);
	}
	if (dir)
	{
		ft_export(1, &dir, env);
		free(dir);
	}
	*env = zeroth;
	return (0);
}
