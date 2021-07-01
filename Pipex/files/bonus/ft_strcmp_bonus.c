/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:44:29 by tde-cama          #+#    #+#             */
/*   Updated: 2021/06/10 10:44:33 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1++ != *str2++)
			return (*(--str1) - *(--str2));
	}
	if (*str1 == *str2)
		return (0);
	return (*str1 - *str2);
}
