/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:59:16 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/14 22:51:43 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_ray get_ray(t_camera camera, double s, double t)
{
	t_ray r;

	//r.orig = camera.origin;
	// r.dir = vec_subtract(
	// vec_add(vec_add(camera.lower_left_corner
	// , vec_multiply(u
	// , camera.horizontal))
	// , vec_multiply(v, camera.vertical))
	// ,camera.origin
	// );
	// return (r);

	t_vec3 rd = vec_multiply(camera.lens_radius, random_in_unit_disk());
	t_vec3 offset = vec_multiply(rd.x, camera.u);
	offset = vec_add(offset, camera.v);
	offset = vec_multiply(rd.y, offset);
	r.orig = vec_add(camera.origin, offset);
	r.dir = vec_add(camera.lower_left_corner, vec_multiply(s,camera.horizontal));
	r.dir = vec_add(r.dir, vec_multiply(t,camera.vertical));
	r.dir = vec_subtract(r.dir, camera.origin);
	r.dir = vec_subtract(r.dir, offset);
	return (r);
}

t_camera set_camera(/*t_image image*/t_point3 lookfrom, t_point3 lookat,t_vec3 vup, double vfov, double aspect_ratio, double aperture, double focus_dist)
{
	t_camera camera;
	camera.theta = degrees_to_radians(vfov);
	camera.h = tan(camera.theta/2);
	camera.viewport_height = 2.0 * camera.h;
	camera.viewport_width = aspect_ratio * camera.viewport_height;

	// camera.viewport_height = 2.0;
    // camera.viewport_width = image.aspect_ratio * camera.viewport_height;
    // camera.focal_length = 1.0;
    // camera.origin = init_vec(0, 0, 0);
	// camera.horizontal = init_vec(camera.viewport_width, 0, 0);
	// camera.vertical = init_vec(0, camera.viewport_height, 0);
    // camera.lower_left_corner = vec_subtract(
	// vec_subtract(
	// vec_subtract(camera.origin, vec_divide(2.0, camera.horizontal))
	// , vec_divide(2.0, camera.vertical))
	// , init_vec(0, 0, camera.focal_length));

	camera.w = unit_vector(vec_subtract(lookfrom, lookat));
    camera.u = unit_vector(cross(vup, camera.w));
    camera.v = cross(camera.w, camera.u);

    camera.origin = lookfrom;
    camera.horizontal = vec_multiply(focus_dist * camera.viewport_width, camera.u);
    camera.vertical = vec_multiply(focus_dist * camera.viewport_height, camera.v);
    camera.lower_left_corner = vec_subtract(camera.origin, vec_divide(2,camera.horizontal));
    camera.lower_left_corner = vec_subtract(camera.lower_left_corner, vec_divide(2,camera.vertical));
    camera.lower_left_corner = vec_subtract(camera.lower_left_corner, vec_multiply(focus_dist,camera.w));
	camera.lens_radius = aperture / 2;

	return (camera);
}
