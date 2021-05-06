/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:37:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/06 18:41:20 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_color	ray_color(t_ray r, t_world *world, int depth)
{
	t_vec3			unit_direction;
	t_hit_record	rec;
	t_params_list	load_params;
	t_ray			scattered;
	t_color			attenuation;

	load_params = set_lstparam_values(r, 0.001, MY_INFINITY, &rec);
	if (depth <= 0)
		return (init_vec(0, 0, 0));
	world->hit = hittable_list_hit;
	unit_direction = unit_vector(r.dir);
	if (!world->hit(&load_params, world->lst))
		return (
			vec_add(vec_multiply(
					1.0 - (world->ambient_ratio * (unit_direction.y + 1.0)),
					world->ambient_light), init_vec(0, 0, 0))
		);
	if (!rec.mat_ptr->scatter(r, rec, &attenuation, &scattered))
		return (emitted(rec.mat_ptr));
	return (vec_multiply_dot(attenuation, ray_color(scattered,
				world, depth - 1)));
}

void	render	(
					t_image image,
					t_camera camera,
					t_world *world,
					t_data *img
				)
{
	t_render	var;

	var.y = image.height - 1;
	while (var.y >= 0)
	{
		var.x = 0;
		while (var.x < image.width)
		{
			var.clr = init_vec(0, 0, 0);
			var.s = 0;
			while (var.s < SAMPLES_PER_PIXEL)
			{
				var.u = ((double)var.x + random_double()) / (image.width - 1);
				var.v = ((double)var.y + random_double()) / (image.height - 1);
				var.r = get_ray(camera, var.u, var.v);
				var.clr = vec_add(var.clr, ray_color(var.r, world, MAX_DEPTH));
				var.s++;
			}
			var.put_clr = write_color(var.clr, SAMPLES_PER_PIXEL);
			my_mlx_pixel_put(img, var.x, image.height - 1 - var.y, var.put_clr);
			var.x++;
		}
		var.y--;
	}
	ft_freelst(world->lst);
}

void	write_bmp_image(
						t_image image,
						t_camera camera,
						t_world *world,
						int fd
						)
{
	t_render	var;

	var.y = 0;
	while (var.y < image.height)
	{
		var.x = 0;
		while (var.x < image.width)
		{
			var.clr = init_vec(0, 0, 0);
			var.s = 0;
			while (var.s < SAMPLES_PER_PIXEL)
			{
				var.u = ((double)var.x + random_double()) / (image.width - 1);
				var.v = ((double)var.y + random_double()) / (image.height - 1);
				var.r = get_ray(camera, var.u, var.v);
				var.clr = vec_add(var.clr, ray_color(var.r, world, MAX_DEPTH));
				var.s++;
			}
			var.put_clr = write_color(var.clr, SAMPLES_PER_PIXEL);
			write_data(fd, var.put_clr);
			var.x++;
		}
		var.y++;
	}
	ft_freelst(world->lst);
}

void	export_bmp(
					t_image image,
					t_camera camera,
					t_world *world,
					char *argv
					)
{
	int				fd;
	t_bmp_header	header;

	fd = create_file(argv);
	header = set_header(image);
	write_header(fd, header);
	write_bmp_image(image, camera, world, fd);
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1++ != *str2++)
			return (*(--str1) - *(--str2));
	}
	if (*str1 == *str2)
		return (0);
	return (*str1 - *str2);
}
