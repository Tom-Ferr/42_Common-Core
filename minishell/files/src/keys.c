/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:06:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/13 16:31:14 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f(char **live, *t_list buff)
{
	if (g_main.j < ft_lstsize(g_main.buff) - 1 && !ft_strcmp(g_main.input, UP))
		g_main.j++;
	else if (j && !ft_strcmp(g_main.input, DOWN))
		g_main.j--;
	load_history(&live, g_main.buff, j);
	i = ft_strlen(g_main.live);
}

void	f(char *side, int u)
{
	write(1, side, 3);
	g_main.i += u;
}
