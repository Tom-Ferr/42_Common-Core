/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:30:23 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/15 10:38:04 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*tcstr;
	char	tcc;
	int		i;

	tcstr = (char*)str;
	tcc = (char)c;
	i = ft_strlen(tcstr);
	while (i && *(tcstr + i) != tcc)
		--i;
	if (*(tcstr + i) == tcc)
		return (tcstr + i);
	return (0);
}
