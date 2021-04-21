/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:57:39 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/17 23:39:00 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}



typedef struct  s_data
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}      			t_data;

typedef struct  s_vars
{
    void        *mlx;
    void        *mlx_win;
}  				t_vars;

int close_program()
{
	exit(0);
	return 1;
}

int key_pressed(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
	 	mlx_destroy_window(vars->mlx, vars->mlx_win);
		close_program();
		return 1;
	}

	return 0;
}


void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main() {

    t_data  img;
	t_vars vars;

	const int image_width = 256;
    const int image_height = 256;
	int r;
	int g = image_height;
	int b = (255.999 * 0.25);

    vars.mlx = mlx_init();
    vars.mlx_win = mlx_new_window(vars.mlx, image_width, image_height, "Hello world!");
    img.img = mlx_new_image(vars.mlx, image_width, image_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                &img.endian);


	while (g--)
	{
		r = 0;
		while (r < image_width)
		{
			int color = create_trgb(0, r, g, b);

			my_mlx_pixel_put(&img, r, image_height-1 - g, color);
			r++;
		}
	}


    mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_key_hook(vars.mlx_win, key_pressed, &vars);
	mlx_hook(vars.mlx_win, 17, 1L<<17, close_program, &vars);
    mlx_loop(vars.mlx);
}
