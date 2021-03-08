/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 00:33:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/07 00:35:02 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_make_str(int n, ...)
{
	va_list my_chars;
	char *str;
	int i;

	va_start(my_chars, n);
	i = 0;
	str = (char *)malloc(n + 1);
	while(n > i)
	{
		str[i] = va_arg(my_chars, int);
		i++;
	}
	str[n] = '\0';
	va_end(my_chars);
	return (str);
}
