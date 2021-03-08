/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_layer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 09:12:50 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/08 11:44:43 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*specifier_layer(va_list args, char *format)
{
	char *temp;
	char *ret;

	if (*format == 'i' || *format == 'd' || *format == 'u')
		temp = ft_itoa(va_arg(args, int));
	else if (*format == 's')
		temp = ft_strdup(va_arg(args, char*));
	else if (*format == 'c')
		temp = ft_make_str(1, va_arg(args, int));
	else if (*format == '%')
		temp = ft_make_str(1, '%');
	else if (*(format) == 'p' || *(format) == 'x'
	||	*(format) == 'X')
		temp = ft_dtox(va_arg(args, long), *format == 'X');
		if (*format == 'p')
			temp = ft_strjoin_free(ft_make_str(2, '0', 'x'), temp);
	else
		return (NULL);
	ret = (char *)malloc(ft_strlen(temp) + 3);
	ft_strlcpy(ret, temp, ft_strlen(temp) + 1);
	ret[ft_strlen(temp) + 1] = *format;
	ret[ft_strlen(temp) + 2] = NULL;
	free(temp);
	return (ret);
}
