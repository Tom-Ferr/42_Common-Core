/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:35:08 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/07 17:48:00 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(int argc, char *argv[], char *env[])
{
	int	i;

	i = 0;
	argc--;
	env = argv;
	while (argv[++i])
	{
		if (ft_strcmp(argv[i], "-n"))
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
