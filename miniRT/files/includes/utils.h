/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:43:43 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/25 11:08:54 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "color.h"
# include "ray.h"
# include "camera.h"
# include "vec3.h"
# include "hittable_list.h"
# include "sphere.h"
# include "numbers.h"
# include "libx_utils.h"
# include "bitmap.h"

typedef struct s_render
{
	t_ray	r;
	int		x;
	int		y;
	int		s;
	t_color	clr;
	double	u;
	double	v;
	int		put_clr;
}			t_render;

void	render(
			t_image image,
			t_camera camera,
			t_hittable_list *world,
			t_data *img
			);
t_color	ray_color(t_ray r, t_hittable_list *world, int depth);
void	write_bmp_image(
			t_image image,
			t_camera camera,
			t_hittable_list *world,
			int fd
			);
void	export_bmp(
			t_image image,
			t_camera camera,
			t_hittable_list *world
			);
#endif
