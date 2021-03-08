/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:27 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/08 11:46:51 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isset(char const s, char const *check)
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
