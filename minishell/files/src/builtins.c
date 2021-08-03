/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:35:08 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/03 17:46:18 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

int	ft_pwd(int argc, char *argv[], char *env[])
{
	char	pwd[256];

	argc--;
	argv = env;
	getcwd(pwd, 256);
	printf("%s\n", pwd);
	return (0);
}
