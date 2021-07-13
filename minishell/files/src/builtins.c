/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:35:08 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/10 19:13:46 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_cd(int argc, char *argv[], char *env[])
{
	char pwd[256];

	if (argc < 2)
		chdir(getenv("HOME"));
	else if(argc < 3)
		chdir(argv[1]);
	else
		write(2, "Too many arguments\n", 19);
	return (0);
}

int ft_echo(int argc, char *argv[], char *env[])
{
	int	i;

	i = 0;
	while(argv[++i])
		if (*argv[i] != '-')
		{
			printf("%s", argv[i]);
			if (argv[i + 1])
				printf(" ");
		}
	if (ft_strcmp(argv[1], "-n"))
		printf("\n");
	return (0);
}

int ft_env(int argc, char *argv[], char *env[])
{
	int	i;

	i = -1;
	while (env[++i])
		printf("%s\n", env[i]);
	return (0);
}

int ft_pwd(int argc, char *argv[], char *env[])
{
	int	i;
	int	j;

	i = -1;
	j = 3;
	while (env[++i])
		if (strstr(env[i], "PWD="))
			while (env[i][++j])
				printf("%c", env[i][j]);
	printf("\n");
	return (0);
}
