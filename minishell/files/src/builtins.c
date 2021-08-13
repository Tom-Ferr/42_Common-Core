/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*   By: nfranco- <nfranco-@student.42.fr>        +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/03 19:38:25 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_checkfound(
							int (*g)(int argc,
							char *argv[],
							t_list *env[]),
							int argc,
							char *argv[]
						)
{
	if (!g(argc, argv, &g_main.env))
	{
		free_star(argv);
		exit (EXIT_SUCCESS);
	}
	else
	{
		free_star(argv);
		printf("Error: %s\n", strerror(errno));
		exit (EXIT_FAILURE);
	}
}

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
