/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_layer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:00:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/08 11:51:16 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*reduce_str(int pr, int len, char *to_print)
{
	char *sr;

	sr = (char *)malloc(pr + 3);
	ft_strlcpy(sr, to_print, pr + 1);
	sr[pr + 1] = to_print[len + 1];
	sr[pr + 2] = NULL;
	free(to_print);
	return (sr);
}

static char		*add_zeros(int pr, int len, char *to_print)
{
	char *zr;
	char *zr_0;
	char *to_print_0;

	if (*to_print == '-')
		pr - (len - 1);
	else
		pr = pr - len;
	if (pr <= len)
		return(to_print);
	zr = (char *)malloc(len + pr + 3);
	zr_0 = zr;
	to_print_0 = to_print;
	if (*to_print == '-')
		*zr++ = *to_print++;
	while (pr--)
		*zr++ = '0';
	while(*to_print)
		*zr++ = *to_print++;
	*zr++ = '\0';
	*zr++ = to_print_0[len + 1];
	*zr = '.';
	free(to_print_0);
	return (zr_0);
}

static char		*core(va_list args, int pr, char *format)
{
	char *to_print;
	int len;

	to_print = print_format(args, format, NULL);
	len = ft_strlen(to_print);
	if (to_print[len + 1] == 's')
		return (reduce_str(pr, len, to_print));
	if (ft_isset(to_print[len + 1], "iduxX") && pr > len)
		return (add_zeros(pr, len, to_print));
	return (to_print);
}

int		precision_layer(va_list args, char *format)
{
	int pr;
	char *dg;

	if (format == '*')
	{
		pr = va_arg(args, int);
		return (core(args, pr, ++format));
	}
	else if (ft_is_digit(format))
	{
		dg = make_str(*format++);
		while (ft_is_digit(*format))
			dg = ft_strjoin_free(dg, ft_make_str(*format++));
		return (core(args, ft_atoi(dg, format)));
	}
	return (core(args, 0, format));
}
