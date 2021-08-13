/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*   By: nfranco- <nfranco-@student.42.fr>        +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/03 19:38:25 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	get_coord_val(char buf[], int *n, char c, int i)
{
	int	pow;

	pow = 1;
	while (buf[--i] != c)
	{
		*n = *n + (buf[i] - '0') * pow;
		pow *= 10;
	}
	return (i);
}

static void	get_pos(int *x, int *y)
{
	int		i;
	char	c;
	char	buf[20];

	write(1, CURSOR_GET, 4);
	i = 0;
	c = 0;
	while (c != 'R')
	{
		read(0, &c, 1);
		buf[i] = c;
		i++;
	}
	i = get_coord_val(buf, x, ';', i - 1);
	i = get_coord_val(buf, y, '[', i);
}

void	lastline_util(struct winsize w)
{
	char	*str;
	int		z;

	str = NULL;
	z = w.ws_row - ++g_main.rows_up;
	if (z < 1)
		z = 1;
	str = ft_strjoin(ft_strdup("\e["), ft_itoa(z), 0);
	str = ft_strjoin(str, ft_strdup(";13H"), 0);
	write(1, str, ft_strlen(str));
	free(str);
	write(1, CURSOR_SAVE, 3);
}

void	check_lastline(char new)
{
	struct winsize	w;
	int				x;
	int				y;
	int				z;

	x = 0;
	y = 0;
	ioctl(0, TIOCGWINSZ, &w);
	get_pos(&x, &y);
	z = w.ws_row - g_main.rows_up;
	if (g_main.rows_up && z == y)
		g_main.rows_up = 0;
	if (y == w.ws_row && x == 2 && new != 127)
		lastline_util(w);
	else
		write(1, CURSOR_REST, 3);
	write(1, CLEAR_END, 3);
}
