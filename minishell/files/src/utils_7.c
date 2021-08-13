/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*   By: nfranco- <nfranco-@student.42.fr>        +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/03 19:38:25 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tcstr1;
	unsigned char	*tcstr2;

	tcstr1 = (unsigned char *)s1;
	tcstr2 = (unsigned char *)s2;
	while (n--)
	{
		if (!*tcstr1 || !*tcstr2 || *tcstr1 != *tcstr2)
			return (*tcstr1 - *tcstr2);
		tcstr1++;
		tcstr2++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, int len)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	l = ft_strlen(needle);
	if (l == 0 || !needle)
		return ((char *)haystack);
	l--;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && j <= l && (i + j) < len)
		{
			if (j == l)
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	free_star(char **me)
{
	int	i;

	i = 0;
	while (me[i])
	{
		free(me[i]);
		i++;
	}
	if (me[i])
		free(me[i]);
	free(me);
}
