/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:57:02 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/17 23:05:21 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx_utils.h"

int		close_program(void)
{
	exit(0);
	return (1);
}

int		key_pressed(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
	 	mlx_destroy_window(vars->mlx, vars->mlx_win);
		close_program();
		return (1);
	}
	return (0);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
