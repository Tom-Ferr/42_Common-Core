/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:01:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/03 17:13:28 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	str_expans(char *live, int i, size_t stop)
{
	while (i > (int)stop)
	{
		live[i] = live[i - 1];
		i--;
	}
}

void	str_retract(char *live, size_t i)
{
	while (live[i])
	{
		live[i - 1] = live[i];
		i++;
	}
	live[i - 1] = live[i];
}

void	str_update(char *live, char new, size_t *i)
{
	int	j;

	if (new != 127 && (new > 31 || new == '\t'))
	{
		if (*i < ft_strlen(live))
			str_expans(live, ft_strlen(live), *i);
		live[*i] = new;
		(*i) += 1;
	}
	else if (*i && new > 31)
	{
		if (*i < ft_strlen(live))
			str_retract(live, *i);
		else
			live[(*i) - 1] = '\0';
		(*i) -= 1;
	}
	check_lastline(new);
	write(1, live, ft_strlen(live));
	j = ft_strlen(live) - *i;
	if (*i < ft_strlen(live))
		while (j--)
			write(1, "\b", 1);
}
