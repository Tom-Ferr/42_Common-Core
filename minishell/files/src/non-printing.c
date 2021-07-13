/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non-printing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:37:31 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/13 14:02:51 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	clear(char *live,  char input, size_t *i)
{
	write(1, CLEAR_SCREEN, 4);
	write(1, CURSOR_HOME, 3);
	str_update(live, input, i);
}

void 	newline(t_list **buff, char *live, size_t *i, int *j)
{
	free_lst(buff);
	live = ft_calloc(800 + 1, sizeof(char));
	get_history(live, buff);
	write(1, "\nminishell > ", 13);
	*i = 0;
	*j = 0;
}

void 	write_history(int fd_hist, char *live)
{
	write(fd_hist, live, ft_strlen(live));
	write(fd_hist, "\n", 1);
}
