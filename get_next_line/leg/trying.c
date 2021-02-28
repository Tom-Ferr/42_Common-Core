/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trying.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:07:57 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/26 09:46:46 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*next;
	int				i;
	char 			*buf;
	char 			*tmp;
	int			nbytes;
	int			bytes_total;
	char			*current;

	buf = (char*)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);

	ft_bzero(buf, BUFFER_SIZE + 1);

	if (next)
	{
		i = ft_strlen(next);
		bytes_total = i;
		free(buf);
		buf = (char*)malloc((bytes_total + BUFFER_SIZE + 1));
		ft_bzero(buf, bytes_total + BUFFER_SIZE + 1);
		ft_strlcpy(&buf[0], &next[0], bytes_total);
		ft_bzero(next, i);
		free(next);
		next = NULL;
	}
	else
	{
		i = 0;
		bytes_total = 0;
	}
	nbytes = 1;
	while (nbytes)
	{
		nbytes = read(fd, &buf[i], BUFFER_SIZE);
		if(nbytes > 0)
		{
			bytes_total +=  nbytes;
			tmp = (char*)malloc((bytes_total + BUFFER_SIZE + 1));
			ft_bzero(tmp, bytes_total + BUFFER_SIZE + 1);
			ft_strlcpy(&tmp[0], &buf[0], bytes_total);
			free(buf);
			buf = &tmp[0];
			tmp = NULL;
			if (distribute(buf, &current, &next))
				break;
			i += nbytes;
		}
	}
	if (!nbytes)
	{
		if (*buf)
		{
			current = ft_strdup(buf);
			*line = current;
		}
		if (buf != tmp)

		return (0);
	}
	if (buf != tmp)
		free(tmp);
	free(buf);
	buf = NULL;
	*line = current;
	return (1);
}
