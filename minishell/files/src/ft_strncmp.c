/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 01:02:41 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/14 16:42:27 by tde-cama         ###   ########.fr       */
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
