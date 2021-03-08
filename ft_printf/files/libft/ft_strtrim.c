/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:27 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/14 23:20:13 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isset(char const s, char const *check)
{
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(check);
	while (i < len)
	{
		if (s == check[i])
			return (1);
		i++;
	}
	return (0);
}

static char		*fill(char const *s1, char *ptr, size_t a, size_t z)
{
	size_t j;

	j = 0;
	while (a <= z)
	{
		ptr[j] = s1[a];
		a++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	a;
	size_t	z;

	a = 0;
	z = ft_strlen(s1) - 1;
	while (s1[a] && isset(s1[a], set))
		a++;
	if (!s1[a])
	{
		ptr = (char*)malloc(1);
		*ptr = '\0';
		return (ptr);
	}
	while (s1[z] && isset(s1[z], set))
		z--;
	ptr = (char*)malloc((z - a) + 2);
	if (!ptr)
		return (0);
	return (fill(s1, ptr, a, z));
}
