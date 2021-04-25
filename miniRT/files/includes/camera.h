/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 09:49:45 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/23 18:46:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec3.h"
# include "ray.h"

typedef struct s_camera
{
	double			viewport_height;
	double			viewport_width;
	double			focal_length;
	t_point3		origin;
	t_vec3			horizontal;
	t_vec3			vertical;
	t_point3		lower_left_corner;
	t_vec3			w;
	t_vec3			u;
	t_vec3			v;
	double			lens_radius;
}					t_camera;

typedef struct s_image
{
	double	aspect_ratio;
	int		width;
	int		height;
}			t_image;

typedef struct s_settings
{
	t_point3	lookfrom;
	t_point3	lookat;
	t_vec3		vup;
	double		focus_dist;
	double		aperture;
}				t_settings;

t_ray		get_ray(t_camera camera, double u, double v);
t_camera	set_camera(double vfov, double aspect_ratio, t_settings set);

#endif
