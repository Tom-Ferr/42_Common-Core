/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/13 11:59:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	get_history(char *live, t_list **buff)
{
	char 	*line;
	char 	*put;
	int		fd;

	fd = open(".history.log", O_RDONLY, S_IRWXU);
	if (fd < 0)
		perror("Error");
	while (get_next_line(fd, &line))
	{
		if (line[0] > 31)
		{
			put = ft_calloc(800 + 1, sizeof(char));
			ft_strlcpy(put, line, ft_strlen(line));
			ft_lstadd_back(buff, ft_lstnew(put));
			free(line);
		}
	}
	if (line[0] > 31)
	{
		put = ft_calloc(800 + 1, sizeof(char));
		ft_strlcpy(put, line, ft_strlen(line));
		ft_lstadd_back(buff, ft_lstnew(put));
		free(line);
	}
	ft_lstadd_back(buff, ft_lstnew(live));
	close(fd);
}

void 	load_history(char **live, t_list *lst, int j)
{
	int	size;

	size = ft_lstsize(lst);
	while (--size > j)
		lst = lst->next;
	*live = lst->content;
	write(1, CLEAR_LINE, 4);
	write(1, "\rminishell > ", 13);
	write(1, *live, ft_strlen(*live));
}
