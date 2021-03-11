/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_layer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:06:26 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/08 12:54:33 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*flags_layer(va_list args, char *format)
{
	if (*format == '-')
		return (width_layer(args, ++format, '-'));
	return (print_format(args, ++format, '0'));
}
