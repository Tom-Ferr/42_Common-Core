/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:13:25 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/09 14:34:34 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_utoa(unsigned int n)
{
	char *m;

	if (n < 10)
		return (ft_make_str(1, (n + '0')));
	m = ft_utoa(n / 10);
	return (ft_strjoin_free(m, ft_make_str(1, ((n % 10) + '0'))));
}
