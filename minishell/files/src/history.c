/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/13 18:31:39 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_history()
{
	int	fd;

	fd = open(".history.log", O_APPEND | O_CREAT | O_RDWR, S_IRWXU);
	if (fd < 0)
	{
		perror("Error:");
		exit(1);
	}
	return (fd);
}

void 	get_history()
{
	char 	*line;
	char 	*put;
	int		fd;

	fd = open_history();
	while (get_next_line(fd, &line))
	{
		if (line[0] > 31)
		{
			put = ft_calloc(800 + 1, sizeof(char));
			ft_strlcpy(put, line, ft_strlen(line));
			ft_lstadd_back(&g_main.buff, ft_lstnew(put));
			free(line);
		}
	}
	if (line[0] > 31)
	{
		put = ft_calloc(800 + 1, sizeof(char));
		ft_strlcpy(put, line, ft_strlen(line));
		ft_lstadd_back(&g_main.buff, ft_lstnew(put));
		free(line);
	}
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
	write(1, CLEAR_LINE, 4);
	write(1, "\rminishell > ", 13);
	write(1, g_main.live, ft_strlen(g_main.live));
}

void 	save_history()
{
	write(g_main.fd_hist, g_main.live, ft_strlen(g_main.live));
	write(g_main.fd_hist, "\n", 1);
}
