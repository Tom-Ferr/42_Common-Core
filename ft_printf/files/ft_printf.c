/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:27:20 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/11 18:06:25 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list args;
	int		p;
	char	*to_print;

	p = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format++ != '%')
			write(1, --format, 1);
		else
		{
			if ((to_print = print_format(args, (char *)format, '\0')) <= 0)
				return (-1);
			p += (ft_putstr_fd(to_print, 1) - 1);
			free(to_print);
			while (!(ft_isset(*format, "cspdiuxX%f")))
				format++;
		}
		format++;
		p++;
	}
	va_end(args);
	return (p);
}
