/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:35:32 by tde-cama          #+#    #+#             */
/*   Updated: 2021/06/08 15:34:04 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	nofwords(char const *s, char c)
{
	size_t	n;
	size_t	i;
	int		count_start;

	n = 0;
	i = 0;
	count_start = 1;
	while (s[i])
	{
		if (s[i] != c && count_start)
		{
			n++;
			count_start = 0;
		}
		else if (s[i] == c)
		{
			count_start = 1;
		}
		i++;
	}
	return (n);
}

static size_t	c_index(char const *s, char c, size_t x)
{
	size_t	i;

	i = x;
	while (s[i])
	{
		if (i && s[i] == c && s[i - 1] != c)
			return (i);
		i++;
	}
	return (i);
}

static size_t	word_len(char const *s, char c, size_t i)
{
	size_t	n;

	n = 0;
	while (s[i])
	{
		if (n && s[i] == c)
			return (n);
		else if (s[i] != c)
			n++;
		i++;
	}
	return (n);
}

static char	*strxtr(char const *src, size_t len, size_t start, size_t w)
{
	char	*xtr;
	size_t	i;

	if (!w)
		return (0);
	i = 0;
	xtr = (char *)malloc(len + 1);
	while (len--)
	{
		xtr[i] = src[start];
		i++;
		start++;
	}
	xtr[i] = '\0';
	return (xtr);
}

char	**ft_split(char const *s, char c)
{
	size_t	w;
	size_t	c_i;
	size_t	r;
	size_t	len;
	char	**ret;

	w = nofwords(s, c);
	r = 1;
	len = word_len(s, c, 0);
	c_i = c_index(s, c, 0);
	ret = (char **)malloc((w + 1) * sizeof(char **));
	if (!ret)
		return (0);
	ret[0] = strxtr(s, len, c_i - len, w);
	while (r < w)
	{
		len = word_len(s, c, c_i);
		c_i = c_index(s, c, (c_i + 1));
		ret[r] = strxtr(s, len, c_i - len, w);
		r++;
	}
	if (w)
		ret[r] = 0;
	return (ret);
}
