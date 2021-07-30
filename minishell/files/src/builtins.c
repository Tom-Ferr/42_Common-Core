/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:35:08 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/26 20:31:53 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cd_util(int argc, char *argv[], t_list **env, char **dir)
{
	char	*home;
	char	*pwd;

	pwd = NULL;
	lst_rewind(*env);
	if (argc < 2)
	{
		home = ft_search_env("HOME", *env);
		if (chdir(home) < 0)
		{
			free(home);
			return (NULL);
		}
		*dir = ft_strjoin(ft_strdup("PWD="), home, 0);
	}
	else if (argc < 3)
	{
		if (chdir(argv[1]) < 0)
			return (NULL);
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
		errno = E2BIG;
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

int	ft_echo(int argc, char *argv[], char *env[])
{
	int	i;

	i = 0;
	argc--;
	if ((argv[1]) && (argv[1][0] == '-' && argv[1][1] != 'n'))
	{
		errno = EINVAL;
		return (1);
	}
	env = argv;
	while (argv[++i])
	{
		if (*argv[i] != '-')
		{
			printf("%s", argv[i]);
			if (argv[i + 1])
				printf(" ");
		}
	}
	if (ft_strcmp(argv[1], "-n"))
		printf("\n");
	return (0);
}

int	ft_env(int argc, char *argv[], char *env[])
{
	int	i;

	if (argc != 1)
	{
		errno = E2BIG;
		return (1);
	}
	argv = env;
	i = -1;
	while (env[++i])
		printf("%s\n", env[i]);
	return (0);
}

int	ft_pwd(int argc, char *argv[], char *env[])
{
	char	pwd[256];

	if (argc != 1)
	{
		errno = E2BIG;
		return (1);
	}
	argv = env;
	getcwd(pwd, 256);
	printf("%s\n", pwd);
	return (0);
}
