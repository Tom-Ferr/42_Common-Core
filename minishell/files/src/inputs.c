/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:37:31 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/13 21:38:14 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	clear()
{
	write(1, CLEAR_SCREEN, 4);
	write(1, CURSOR_HOME, 3);
	str_update(g_main.live, g_main.input[0], &g_main.i);
}

void 	newline()
{
	free_lst(&g_main.buff);
	g_main.live = ft_calloc(800 + 1, sizeof(char));
	get_history();
	write(1, "\nminishell > ", 13);
	g_main.i = 0;
	g_main.j = 0;
}

void	check_input()
{
	if (g_main.input[0] > 31)
		str_update(g_main.live, g_main.input[0], &(g_main.i));
	else if(g_main.input[0] == '\e' && g_main.input[1] == '[')
		arrow_keys();
	else if (g_main.input[0] == CTRL_L)
		clear();
	else if (g_main.input[0] == '\n' )
	{
		if (g_main.live[0])
			save_history();
		newline();
	}
}
