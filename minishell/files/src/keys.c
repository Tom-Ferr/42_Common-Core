/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:06:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/13 21:22:30 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	v_keys()
{
	if (g_main.j < ft_lstsize(g_main.buff) - 1 && !ft_strcmp(g_main.input, UP))
		g_main.j++;
	else if (g_main.j && !ft_strcmp(g_main.input, DOWN))
		g_main.j--;
	load_history(g_main.buff);
	g_main.i = ft_strlen(g_main.live);
}

void	h_keys(char *side, int u)
{
	write(1, side, 3);
	g_main.i += u;
}

void	arrow_keys()
{
	if (!ft_strcmp(g_main.input, UP))
		v_keys();
	else if (!ft_strcmp(g_main.input, DOWN))
		v_keys();
	else if (!ft_strcmp(g_main.input, RIGHT) && g_main.i < ft_strlen(g_main.live))
		h_keys(RIGHT, 1);
	else if (!ft_strcmp(g_main.input, LEFT) && g_main.i)
		h_keys(LEFT, -1);
}
