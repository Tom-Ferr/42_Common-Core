/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:37:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/21 18:14:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_color	ray_color(t_ray r, t_hittable_list *world, int depth)
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
	if (world->hit(&load_params, world))
	{
		if (rec.mat_ptr->scatter(r, rec, &attenuation, &scattered))
			return (vec_multiply_dot(attenuation, ray_color(scattered,
						world, depth - 1)));
		return (init_vec(0, 0, 0));
	}
	unit_direction = unit_vector(r.dir);
	return (
		vec_add(vec_multiply(1.0 - (0.5 * (unit_direction.y + 1.0)),
				init_vec(1.0, 1.0, 1.0)),
			vec_multiply((0.5 * (unit_direction.y + 1.0)),
				init_vec(0.5, 0.7, 1.0)))
	);
}

void	render	(
					t_image image,
					t_camera camera,
					t_hittable_list *world,
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
	ft_freelst(world);
}
