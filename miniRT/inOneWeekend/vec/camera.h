/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 09:49:45 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/14 22:50:51 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec3.h"
# include "ray.h"

typedef struct		s_camera
{
    double			theta;
    double			h;
	double			viewport_height;
    double			viewport_width;
    double			focal_length;
    t_point3			origin;
    t_vec3			horizontal;
    t_vec3			vertical;
    t_point3			lower_left_corner;

	t_vec3 			w;
	t_vec3 			u;
	t_vec3 			v;
	double 			lens_radius;
}					t_camera;

typedef struct		s_image
{
	double	aspect_ratio;
	int		width;
	int		height;
}					t_image;

t_ray get_ray(t_camera camera, double u, double v);
t_camera set_camera(/*t_image image*/t_point3 lookfrom, t_point3 lookat,t_vec3 vup, double vfov, double aspect_ratio, double aperture, double focus_dist);

#endif
