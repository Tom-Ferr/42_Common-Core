/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:16:36 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/09 11:32:07 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	char	*tcstr;
	size_t	size;

	if (!str)
		return (ft_make_str(6, '(', 'n', 'u', 'l', 'l', ')'));
	tcstr = (char*)str;
	size = ft_strlen(tcstr) + 1;
	ptr = (char*)malloc(size);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, tcstr, size);
	return (ptr);
}
