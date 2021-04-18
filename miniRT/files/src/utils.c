/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:37:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/18 11:05:11 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_color ray_color(t_ray r, t_hittable_list *world, int depth)
{
    t_vec3 unit_direction;
	t_hit_record rec;
	t_params_list load_params;
	t_ray scattered;
	t_color attenuation;

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
    return
	(
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
	t_ray r;
	t_point3 coord;
	t_color pixel_clr;
	t_color multplr;
	int put_clr;

    coord.y = image.height - 1;
	while (coord.y >= 0)
	{
		coord.x = 0;
        while (coord.x < image.width)
		{
            pixel_clr = init_vec(0, 0, 0);
			coord.z = 0;
			while (coord.z < SAMPLES_PER_PIXEL)
			{
				multplr.x = (coord.x + random_double()) / (image.width - 1);
	            multplr.y = (coord.y + random_double()) / (image.height - 1);
	            r = get_ray(camera, multplr.x, multplr.y);
				pixel_clr = vec_add(pixel_clr, ray_color(r, world, MAX_DEPTH));
				coord.z++;
			}
        	put_clr = write_color(pixel_clr, SAMPLES_PER_PIXEL);
			my_mlx_pixel_put(img, coord.x, image.height - 1 - coord.y, put_clr);
			coord.x++;
        }
		coord.y--;
    }
}
