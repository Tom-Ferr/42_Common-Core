/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:00:31 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/11 17:37:54 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		checkout(char *s, int len, int i)
{
	if (s[len + 1] == 'C' && s[i] == '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int		ft_putstr_fd(char *s, int fd)
{
	int i;
	int len;

	len = ft_strlen(s);
	i = 0;
	if (s[0] == '\0' && ft_isset(s[len + 1], " 0cC"))
	{
		write(1, &s[0], 1);
		i++;
		if (s[0] == '\0' && ft_isset(s[1], "cC"))
			return (i);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
		if (s[len + 2] == 'C' && s[i] == '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (checkout(s, len, i));
}
