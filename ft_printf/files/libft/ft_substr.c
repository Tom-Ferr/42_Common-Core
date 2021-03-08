/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:59:44 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/16 15:20:01 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	lenstr;
	char	*ptr;

	i = 0;
	lenstr = ft_strlen(s);
	if (len > lenstr)
		len = lenstr;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (0);
	if (start < lenstr)
	{
		while (len--)
		{
			ptr[i] = s[i + start];
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}
