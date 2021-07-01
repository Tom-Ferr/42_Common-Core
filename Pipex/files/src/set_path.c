/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:04:03 by tde-cama          #+#    #+#             */
/*   Updated: 2021/06/01 22:36:39 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	continue_main(char ***argv, int fd[])
{
	char	*temp;
	char	*swap;
	char	**buff;

	wait(NULL);
	close(fd[1]);
	temp = (char *)malloc(100);
	if (read(fd[0], temp, 100) < 0)
		perror("Error");
	close(fd[0]);
	swap = *argv[0];
	buff = ft_split(temp, ' ');
	free(temp);
	if (buff[1])
	{
		*argv[0] = buff[1];
		buff[1] = swap;
	}
	free_star(buff);
}

void	set_path(char ***argv, char *envp[])
{
	int		fd[2];
	int		id;
	char	*arr[3];

	if (pipe(fd) < 0)
		perror("Error");
	id = fork();
	if (id < 0)
		perror("Error");
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		arr[0] = "/usr/bin/whereis";
		arr[1] = *argv[0];
		arr[2] = NULL;
		close(fd[1]);
		execve(arr[0], arr, envp);
		perror("Error");
	}
	else
		continue_main(argv, fd);
}
