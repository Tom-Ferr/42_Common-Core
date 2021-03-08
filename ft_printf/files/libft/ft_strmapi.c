/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:59:11 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/14 23:15:49 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	char			*ret;
	char			*tcs;
	unsigned int	i;

	tcs = (char *)s;
	ptr = (char*)malloc(ft_strlen(tcs) + 1);
	ret = ptr;
	i = 0;
	if (!ptr)
		return (0);
	while (*s)
	{
		*ptr++ = f(i, *s);
		s++;
		i++;
	}
	*ptr = '\0';
	return (ret);
}
