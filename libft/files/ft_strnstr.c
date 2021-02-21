/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 22:32:14 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/16 14:32:52 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*loop(const char *big, const char *little, const char *s_little,
				size_t len)
{
	char		*ret;

	while (*big && --len)
	{
		if (*little == *big)
		{
			ret = (char*)big;
			while (*little == *big && *little && len)
			{
				little++;
				big++;
				len--;
			}
			if (!*little)
				return (ret);
		}
		little = s_little;
		if (*big == *little)
		{
			big = ret;
			len += 2;
		}
		big++;
	}
	return (0);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!*little)
		return ((char *)big);
	if (ft_strlen(big) < ft_strlen(little))
		return (0);
	return (loop(big, little, little, len + 1));
}
