/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:07:57 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/27 20:04:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		start(char **buf, char **next, int *i, int *bytes_total)
{
	*buf = (char*)malloc(BUFFER_SIZE + 1);
	if (!*buf)
		return (-1);
	ft_bzero(*buf, BUFFER_SIZE + 1);
	if (*next)
	{

		*i = ft_strlen(*next);
		*bytes_total = *i;
		free(*buf);
		*buf = (char*)malloc((*bytes_total + BUFFER_SIZE + 1));
		ft_bzero(*buf, *bytes_total + BUFFER_SIZE + 1);
		ft_strlcpy(*buf, *next, *bytes_total);
		ft_bzero(*next, *i);
		free(*next);
		*next = 0;
	}
	else
	{
		*i = 0;
		*bytes_total = 0;
	}
	return (1);
}

static void		update_buffer(int *bytes_total, int *nbytes, char **buf)
{
	char 	*tmp;

	*bytes_total +=  *nbytes;
	tmp = (char*)malloc((*bytes_total + BUFFER_SIZE + 1));
	ft_bzero(tmp, *bytes_total + BUFFER_SIZE + 1);
	ft_strlcpy(&tmp[0], *buf, *bytes_total);
	free(*buf);
	*buf = &tmp[0];
	tmp = NULL;
}

static int		newlap(char **buf, char **current, char ***line)
{
	free(*buf);
	*buf = NULL;
	**line = *current;
	return (1);
}

static int		checkout(char **current, char **next, char **buf, char ***line)
{
	if (**buf)
	{
		if (!distribute(*buf, current, next))
		{
			free(*buf);
			**line = ft_strdup(*buf);
			return (0);
		}
		return (newlap(buf, current, line));
	}
	free(*buf);
	**line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*next;
	int				i;
	char 			*buf;
	int				nbytes;
	int				bytes_total;
	char			*current;

	if (fd < 0 || !line || fd > RLIMIT_NOFILE || BUFFER_SIZE <= 0
		|| start(&buf, &next, &i, &bytes_total) < 0)
		return (-1);
	nbytes = 1;
	while (nbytes)
	{
		nbytes = read(fd, &buf[i], BUFFER_SIZE);
		if(nbytes > 0)
		{
			update_buffer(&bytes_total, &nbytes, &buf);
			if (distribute(buf, &current, &next))
				break;
			i += nbytes;
		}
	}
	if (!nbytes)
		return (checkout(&current, &next, &buf, &line));
	return (newlap(&buf, &current, &line));
}
