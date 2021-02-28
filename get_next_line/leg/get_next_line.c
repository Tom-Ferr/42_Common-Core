/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:07:57 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/18 19:05:57 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static int	count;
	char 		*buf;

	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (-1);
	while (buf[count] != '\n' || buf[count] != EOF )
	{
		read(fd, buf, count + 1);
		count++;
	}
	if (buff[count] == EOF)
	{
		free(buf);
		return (0);
	}
	buff[count] = '\0';
	*line = strlcpy(*line, buf, count - 1);
	free(buf);
	count++;
	return (1);
}
