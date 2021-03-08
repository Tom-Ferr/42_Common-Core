/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:27:20 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/08 11:48:34 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*print_format(va_list args, char *format, char flag)
{
	if (ft_isset(format, "cspdiuxX%"))
		specifier_layer(args, format);
	else if (format == '.')
		precision_layer(args, ++format);
	else if (isset(format, "-0"))
		flags_layer(args, format);
	else if (format == '*' || ft_is_digit(format))
		width_layer(args, format, flag);
	else
		return (NULL);
}

int				ft_printf(const char *format, ...)
{
	va_list args;
	int p;
	char *to_print;

	p = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format++ != '%')
			write(1, --format, 1);
		else
		{
			if ((to_print = print_format(args, format, NULL)) <= 0)
				return (-1)
			ft_putstr_fd(1, to_print);
			p += (ft_strlen(to_print) - 1);
			free(to_print);
			while (!(ft_isset(*format, "cspdiuxX%"))
				format++;
		}
		format++;
		p++;
	}
	va_end(args);
	return (p);
}
