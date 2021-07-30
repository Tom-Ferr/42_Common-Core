/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/29 11:37:57 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_history(char *file)
{
	int	fd;

	fd = open(file, O_APPEND | O_CREAT | O_RDWR, S_IRWXU);
	if (fd < 0)
	{
		perror("Error:");
		exit(1);
	}
	return (fd);
}

void 	get_history(void)
{
	char	*line;
	char	*put;
	int		fd;

	fd = open_history("/tmp/.history.log");
	while (get_next_line(fd, &line))
	{
		if (line[0] > 31)
		{
			put = ft_calloc(800 + 1, sizeof(char));
			ft_strlcpy(put, line, ft_strlen(line));
			ft_lstadd_back(&g_main.buff, ft_lstnew(put));
		}
		free(line);
	}
	if (line[0] > 31)
	{
		put = ft_calloc(800 + 1, sizeof(char));
		ft_strlcpy(put, line, ft_strlen(line));
		ft_lstadd_back(&g_main.buff, ft_lstnew(put));
	}
	free(line);
	ft_lstadd_back(&g_main.buff, ft_lstnew(g_main.live));
	close(fd);
}

void 	load_history(t_list *lst)
{
	int	size;

	size = ft_lstsize(lst);
	while (--size > g_main.j)
		lst = lst->next;
	g_main.live = lst->content;
	write(1, "\e[u", 3);
	write(1, "\e[J", 3);
	write(1, g_main.live, ft_strlen(g_main.live));
}

void 	save_history(void)
{
	write(g_main.fd_hist, g_main.live, ft_strlen(g_main.live));
	write(g_main.fd_hist, "\n", 1);
}
