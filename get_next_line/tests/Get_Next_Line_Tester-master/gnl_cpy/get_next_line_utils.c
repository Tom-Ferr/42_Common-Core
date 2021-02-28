/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:02:03 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/28 09:56:53 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlcpy(char *dest, const char *src, size_t size)
{
	char *tcsrc;

	tcsrc = (char*)src;
	if (!src)
		return (0);
	if (size)
	{
		while (size-- && *tcsrc)
			*dest++ = *tcsrc++;
	}
	return (ft_strlen(src));
}

static void		prepare_next(size_t rest_len, char *buf, char **next, size_t j)
{
	size_t	i;
	char	*xtr;

	if (rest_len <= 0)
		*next = 0;
	else
	{
		xtr = (char*)malloc(rest_len + 1);
		ft_bzero(xtr, rest_len + 1);
		i = 0;
		j++;
		while (rest_len > 0)
		{
			xtr[i] = buf[j];
			i++;
			j++;
			rest_len--;
		}
		*next = &xtr[0];
	}
}

int				distribute(char *buf, char **current, char **next)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*xtr;
	size_t	rest_len;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && i < ft_strlen(buf))
		i++;
	if (i >= ft_strlen(buf))
		return (0);
	len = i + 1;
	rest_len = ft_strlen(buf) - len;
	xtr = (char*)malloc(i + 1);
	ft_bzero(xtr, i + 1);
	while (j < i)
	{
		xtr[j] = buf[j];
		j++;
	}
	*current = &xtr[0];
	prepare_next(rest_len, buf, next, j);
	return (1);
}

void			*ft_bzero(void *str, size_t n)
{
	char *tcstr;

	tcstr = (char*)str;
	while (n--)
		*(tcstr++) = '\0';
	return (str);
}

size_t			ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}
