/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:57:02 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/10 23:59:27 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx_utils.h"
#include "hittable_list.h"

int	error_exit(char *error)
{
	printf("Error: %s\n", error);
	exit(EXIT_FAILURE);
	return (1);
}

int	close_program(t_vars *vars)
{
	ft_freelst(vars->lst);
	exit(0);
	return (1);
}

int	key_pressed(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		ft_freelst(vars->zeroth);
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
		return (1);
	}
	if (keycode != ENTER)
		return (1);
	if (vars->lst->next)
	{
		vars->lst = vars->lst->next;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->lst->obj->data.img, 0, 0);
	}
	else
	{
		vars->lst = vars->zeroth;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->lst->obj->data.img, 0, 0);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
