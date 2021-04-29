/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:01:12 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/27 16:07:18 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	run_mlx(t_image image, t_camera camera, t_hittable_list *world)
{
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, image.width, image.height,
			"tde-cama's miniRT");
	img.img = mlx_new_image(vars.mlx, image.width, image.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	render(image, camera, world, &img);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_key_hook(vars.mlx_win, key_pressed, &vars);
	mlx_hook(vars.mlx_win, 17, 1L << 17, close_program, &vars);
	mlx_loop(vars.mlx);
}
