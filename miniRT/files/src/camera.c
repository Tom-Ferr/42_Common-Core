/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:59:16 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/27 10:31:45 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_ray	get_ray(t_camera camera, double s, double t)
{
	t_ray	r;
	t_vec3	rd;
	t_vec3	offset;

	rd = vec_multiply(camera.lens_radius, random_in_unit_disk());
	offset = vec_multiply(rd.x, camera.u);
	offset = vec_add(offset, camera.v);
	offset = vec_multiply(rd.y, offset);
	r.orig = vec_add(camera.origin, offset);
	r.dir = vec_add(
			camera.lower_left_corner, vec_multiply(s, camera.horizontal));
	r.dir = vec_add(r.dir, vec_multiply(t, camera.vertical));
	r.dir = vec_subtract(r.dir, camera.origin);
	r.dir = vec_subtract(r.dir, offset);
	return (r);
}

t_camera	set_camera(double aspect_ratio, t_settings set)
{
	t_camera	camera;
	double		h;
	double		theta;

	theta = degrees_to_radians(set.vfov);
	h = tan(theta / 2);
	camera.viewport_height = 2.0 * h;
	camera.viewport_width = aspect_ratio * camera.viewport_height;
	camera.w = unit_vector(vec_subtract(set.lookfrom, set.lookat));
	camera.u = unit_vector(cross(set.vup, camera.w));
	camera.v = cross(camera.w, camera.u);
	camera.origin = set.lookfrom;
	camera.horizontal = vec_multiply(
			set.focus_dist * camera.viewport_width, camera.u);
	camera.vertical = vec_multiply(
			set.focus_dist * camera.viewport_height, camera.v);
	camera.lower_left_corner = vec_subtract(
			camera.origin, vec_divide(2, camera.horizontal));
	camera.lower_left_corner = vec_subtract(
			camera.lower_left_corner, vec_divide(2, camera.vertical));
	camera.lower_left_corner = vec_subtract(
			camera.lower_left_corner, vec_multiply(set.focus_dist, camera.w));
	camera.lens_radius = set.aperture / 2;
	return (camera);
}
