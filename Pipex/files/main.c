/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:49:35 by tde-cama          #+#    #+#             */
/*   Updated: 2021/06/08 17:41:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	flow_pipe(int x, int fd[], char *argv, char *envp[])
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	close(fd[1 - x]);
	set_path(&cmd, envp);
	dup2(fd[x], x);
	close(fd[x]);
	execve(cmd[0], cmd, envp);
	free_star(cmd);
	write(2, "Error: Command not found\n", 25);
}

static void	child(int fd[], char *argv[], char *envp[])
{
	int		file;

	file = open(argv[1], O_RDONLY);
	if (file < 0)
	{
		perror("Error");
		exit(-1);
	}
	dup2(file, 0);
	flow_pipe(1, fd, argv[2], envp);
}

static void	parent(int fd[], int argc, char *argv[], char *envp[])
{
	int	file;

	wait(NULL);
	file = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR);
	if (file < 0)
		perror("Error");
	dup2(file, 1);
	flow_pipe(0, fd, argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		id;

	if (argc != 5)
	{
		write(2, "Error: 4 arguments are required, no more, no less\n", 49);
		exit(-1);
	}
	if (pipe(fd) < 0)
		perror("Error");
	id = fork();
	if (id < 0)
		perror("Error");
	else if (id == 0)
		child(fd, argv, envp);
	else
		parent(fd, argc, argv, envp);
	return (0);
}
