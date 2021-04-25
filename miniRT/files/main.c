/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:39:43 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/25 12:46:07 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <string.h>

int main(int argc, char **argv)
{
	t_image image;
	t_camera camera;
	t_hittable_list *world;
	t_settings set;

	set.lookfrom = init_vec(-2,0.5,2);
	set.lookat = init_vec(0,0,-1);
	set.vup = init_vec(0,1,0);
	set.focus_dist = length(vec_subtract(set.lookfrom,set.lookat));
	set.aperture = 0;


	t_material material_ground = set_material	(init_vec(0.8, 0.8, 0.0), NONE, NONE, lambertian);
	t_material material_center = set_material	(init_vec(0.1, 0.2, 0.5), NONE, NONE, lambertian);
	t_material material_left = set_material		(init_vec(NONE, NONE, NONE), NONE, 1.5, dielectric);
	t_material material_right = set_material	(init_vec(0.8, 0.6, 0.2), 0, NONE, metal);

	t_sphere sph0 = init_sphere(init_vec(0,-100.5,-1), 100, &material_ground);
	t_sphere sph1 = init_sphere(init_vec(0,0,-1), 0.5, &material_center);
	t_sphere sph2 = init_sphere(init_vec(-1,0,-1), 0.5, &material_left);
	t_sphere sph3 = init_sphere(init_vec(1,0,-0.3), 0.5, &material_right);

	world = ft_lstnew(&sph0);
	ft_lstadd_back(&world, ft_lstnew(&sph1));
	ft_lstadd_back(&world, ft_lstnew(&sph2));
	ft_lstadd_back(&world, ft_lstnew(&sph3));

	image.aspect_ratio = 16.0 / 9.0;
	image.width = 400;
	image.height = image.width / image.aspect_ratio;

    camera = set_camera(45, image.aspect_ratio, set);


	t_data  img;
	t_vars vars;
	vars.mlx = mlx_init();
    vars.mlx_win = mlx_new_window(vars.mlx, image.width, image.height, "tde-cama's miniRT");
    img.img = mlx_new_image(vars.mlx, image.width, image.height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                &img.endian);

	if (strcmp(argv[argc - 1], "--save"))
	{
		render(image, camera, world, &img);
		mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
		mlx_key_hook(vars.mlx_win, key_pressed, &vars);
		mlx_hook(vars.mlx_win, 17, 1L<<17, close_program, &vars);
    	mlx_loop(vars.mlx);
	}
	else
		export_bmp(image, camera, world);
}
