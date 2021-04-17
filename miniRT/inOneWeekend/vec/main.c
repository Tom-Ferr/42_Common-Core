/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:39:43 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/17 00:15:05 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ray.h"
#include "camera.h"
#include "vec3.h"
#include "hittable_list.h"
#include "sphere.h"
#include "numbers.h"

t_color ray_color(t_ray r, t_hittable_list *world, int depth)
{
	double t;
    t_vec3 unit_direction;
	t_hit_record rec;
	t_params_list load_params = set_lstparam_values(r, 0.001, MY_INFINITY, &rec);
	if (depth <= 0)
	   return (init_vec(0,0,0));
	world->hit = hittable_list_hit;
    if (world->hit(&load_params, world))
	{
		t_ray scattered;
		t_color attenuation;
			if (rec.mat_ptr->scatter(r, rec, &attenuation, &scattered))
				return (vec_multiply_dot(attenuation, ray_color(scattered, world, depth - 1)));
			return (init_vec(0,0,0));
		// t_point3 target = vec_add(vec_add(load_params.rec->p, load_params.rec->normal), random_unit_vector());
		// return (vec_multiply(0.5, ray_color(cast_ray(load_params.rec->p, vec_subtract(target, load_params.rec->p)), world, depth - 1)));
        // return (vec_multiply(0.5, (vec_add(load_params.rec->normal, init_vec(1, 1, 1)))));
    }

	unit_direction = unit_vector(r.dir);
    t = 0.5 * (unit_direction.y + 1.0);
    return
	(
		vec_add
		(
			vec_multiply(1.0 - t, init_vec(1.0, 1.0, 1.0)),
			vec_multiply(t, init_vec(0.5, 0.7, 1.0))
		)
	);
}

int main(void)
{
	t_image image;
	t_camera camera;
	t_hittable_list *world;
	int j;
	int i;
	int s;
	t_ray r;
	const int max_depth = 50;

	t_point3 lookfrom = init_vec(3,3,2);
	t_point3 lookat = init_vec(0,0,-1);
	t_vec3 vup = init_vec(0,1,0);
	double dist_to_focus = length(vec_subtract(lookfrom,lookat));
	double aperture = 2.0;


	t_material material_ground = set_material	(init_vec(0.8, 0.8, 0.0), NONE, NONE, lambertian);
	t_material material_center = set_material	(init_vec(0.1, 0.2, 0.5), NONE, NONE, lambertian);
	t_material material_left = set_material		(init_vec(NONE, NONE, NONE), NONE, 1.5, dielectric);
	t_material material_right = set_material	(init_vec(0.8, 0.6, 0.2), 0, NONE, metal);

	t_sphere sph0 = init_sphere(init_vec(0,-100.5,-1), 100, &material_ground);
	t_sphere sph1 = init_sphere(init_vec(0,0,-1), 0.5, &material_center);
	t_sphere sph2 = init_sphere(init_vec(-1,0,-1), -0.45, &material_left);
	t_sphere sph3 = init_sphere(init_vec(1,0,-1), 0.5, &material_right);

	world = ft_lstnew(&sph0);
	ft_lstadd_back(&world, ft_lstnew(&sph1));
	ft_lstadd_back(&world, ft_lstnew(&sph2));
	ft_lstadd_back(&world, ft_lstnew(&sph3));

	// double R = cos(PI/4);
	//
    // t_material material_left  = set_material(init_vec(0.0, 0.0, 1.0), NONE, NONE, lambertian);
    // t_material material_right  = set_material(init_vec(1.0, 0.0, 0.0), NONE, NONE, lambertian);
	//
	// t_sphere sph0 = init_sphere(init_vec(-R,0,-1), R, &material_left);
   	// t_sphere sph1 = init_sphere(init_vec(R,0,-1), R, &material_right);
	//
	// world = ft_lstnew(&sph0);
	// ft_lstadd_back(&world, ft_lstnew(&sph1));



	image.aspect_ratio = 16.0 / 9.0;
	image.width = 400;
	image.height = image.width / image.aspect_ratio;
	const int samples_per_pixel = 100;

    camera = set_camera(lookfrom, lookat, vup, 20, image.aspect_ratio, aperture, dist_to_focus);

//Render
	printf("P3\n%i %i\n255\n", image.width, image.height);

    j = image.height - 1;
	while (j >= 0)
	{
		i = 0;
        while (i < image.width)
		{
            t_color pixel_color = init_vec(0, 0, 0);
			s = 0;
			while (s < samples_per_pixel)
			{
				double u = ((double)i + random_double()) / (image.width - 1);
	            double v = ((double)j + random_double()) / (image.height - 1);
	            r = get_ray(camera, u, v);
				pixel_color = vec_add(pixel_color, ray_color(r, world, max_depth));
				s++;
			}
            write_color(pixel_color, samples_per_pixel);
			i++;
        }
		j--;
    }
}
