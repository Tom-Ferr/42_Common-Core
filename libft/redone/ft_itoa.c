/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:13:25 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/20 14:18:15 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_itoa(int n)
{
	char *m;
	char *s;

	s = ft_strdup("");
	if (n < 0)
		{
			free(s);
			if (n == -2147483648
				return (ft_strdup("-2147483648"));
			s = ft_make_str(1, '-');
			n *= -1;
		}
		if (n < 10)
			return (ft_strjoin_free(s, ft_make_str(1, (n + '0'))));
		m = ft_strjoin_free(s, ft_itoa(n / 10));
		return (ft_strjoin_free(m, ft_make_str(1, ((n % 10) + '0'))));
}
