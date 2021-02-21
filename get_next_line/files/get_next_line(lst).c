/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line(lst).c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:07:57 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/19 11:13:50 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	t_list			*current;
	static off_t	prev;
	char 			*buf;

	if (!prev)
	{
		buf = malloc(BUFFER_SIZE);
		if (!buf)
			return (-1)
		read(fd, buf, BUFFER_SIZE);
		strlcpy(buf2, buf, len)
		current = lstnew(buf2);
		line = current->content;
		free(buf2);
		strlcpy(buf2, buf, len)
		next = lstnew(buf2);
		current->next = next;
		free(buf);
		free(buf2);
		prev += strlen(current->content);
	}

	if (!buf)
		return (-1);
	while (buf[i] != '\n' || buf[i] != EOF )
	{
		read(fd, buf, count);
		i++;
		count++;
	}

	if (buff[i] == EOF)
	{
		free(buf);
		return (0);
	}
	buff[i] = '\0';
	*line = strlcpy(*line, buf, i - 1);
	free(buf);
	return (1);
}
