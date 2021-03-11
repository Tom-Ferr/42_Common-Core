/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_layer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:20:21 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/10 23:54:17 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*add_zeros(int pr, int len, char *to_print)
{
	char *zr;
	char *zr_0;
	char *to_print_0;

	if (pr <= len)
		return(to_print);
	pr = pr - len;
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

static char		*add_pads(int pr, int len, char *to_print, char flag)
{
	char *pd;
	char *ret;
	char pads;
	char sp;

	pads = ' ';
	if (flag == '0')
		pads = '0';
	if (pr <= len)
		return (to_print);
	pr = pr - len;
	sp = to_print[len + 1];
	pd = (char *)malloc(pr + 1);
	ft_memset(pd, pads, pr);
	pd[pr] = '\0';
	len = ft_strlen(pd) + ft_strlen(to_print);
	if (to_print[0] == '\0' && ft_isset(to_print[1], "cC"))
		len++;
	if (flag == '-')
		pd = ft_strjoin_free(to_print, pd);
	else
		pd = ft_strjoin_free(pd, to_print);
	ret = (char *)malloc(len + 2);
	ft_strlcpy(ret, pd, len + 1);
	ret[len + 1] = sp;
	free(pd);
	return (ret);
}

static char		*core(va_list args, int pr, char flag, char *format)
{
	char *to_print;
	int len;

	to_print = print_format(args, format, flag);
	len = ft_strlen(to_print);
	if (pr < 0)
	{
		flag = '-';
		pr *= -1;
	}
	if (to_print[0] == '\0' && to_print[len + 1] == 'c')
	{
		pr--;
		to_print[len + 1] = 'C';
	}
	if (flag == '0' && to_print[len + 2] == '.' && to_print[len + 1] != '%')
		flag = '\0';
	if (flag == '0' && to_print[len + 2] != '.')
		return (add_zeros(pr, len, to_print));
	return (add_pads(pr, len, to_print, flag));
}

char			*width_layer(va_list args, char *format, char flag)
{
	int pr;
	char *dg;

	if (ft_isdigit(*format))
	{
		dg = ft_make_str(1, *format++);
		while (ft_isdigit(*format))
			dg = ft_strjoin_free(dg, ft_make_str(1, *format++));
		return (core(args, ft_atoi(dg), flag, format));
	}
	else if (*format == '*')
	{
		pr = va_arg(args, int);
		return (core(args, pr, flag, ++format));
	}
	return(print_format(args, format, flag));
}
