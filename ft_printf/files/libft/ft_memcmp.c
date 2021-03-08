/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:18:53 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/14 16:42:27 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char *tcstr1;
	unsigned char *tcstr2;

	tcstr1 = (unsigned char*)str1;
	tcstr2 = (unsigned char*)str2;
	while (n--)
	{
		if (*tcstr1 != *tcstr2)
			return (*tcstr1 - *tcstr2);
		tcstr1++;
		tcstr2++;
	}
	return (0);
}
