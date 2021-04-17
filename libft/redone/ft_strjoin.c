/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:27 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/20 14:33:08 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	char		*ptr;
	char		*s1_0;
	char		*s2_0;
	char		*ptr_0;

	s1_0 = (char *)s1;
	s2_0 = (char *)s2;
	size = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	ptr = (char*)malloc(size);
	if (!ptr)
		return (0);
	ptr_0 = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	free(s1_0);
	free(s2_0);
	return (ptr_0);
}
