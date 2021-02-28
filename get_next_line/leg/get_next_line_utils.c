/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:02:03 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/26 11:01:47 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
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

int		distribute(char *buf, char **current, char **next)
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
	xtr = (char*)malloc(i);
	ft_bzero(xtr, i);
	while (j < i)
	{
		xtr[j] = buf[j];
		j++;
	}
	xtr[j] = '\0';
	*current = &xtr[0];
	if (rest_len <= 0)
	{
		xtr = 0;
		*next = 0;
	}
	else
	{
		xtr = (char*)malloc(rest_len + 1);
		ft_bzero(xtr, rest_len + 1);
		i = 0;
		j++;
		while (rest_len > 0)
		{
			xtr[i] = buf [j];
			i++;
			j++;
			rest_len--;
		}
		xtr[j] = '\0';
		*next = &xtr[0];
	}
	return (1);
}

void	*ft_bzero(void *str, size_t n)
{
	char *tcstr;

	tcstr = (char*)str;
	while (n--)
		*(tcstr++) = '\0';
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	char	*tcstr;
	size_t	size;

	tcstr = (char*)str;
	size = ft_strlen(tcstr) + 1;
	ptr = (char*)malloc(size);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, tcstr, size);
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	size_t		size;
	char		*ptr;

	i = 0;
	j = 0;
	size = (ft_strlen(s1) + ft_strlen(s2));
	ptr = (char*)malloc(size);
	if (!ptr)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tcdest;
	const char	*tcsrc;

	tcdest = (char*)dest;
	tcsrc = (const char*)src;
	if (!dest && !src)
		return (0);
	while (n--)
		*(tcdest++) = *(tcsrc++);
	return (dest);
}
