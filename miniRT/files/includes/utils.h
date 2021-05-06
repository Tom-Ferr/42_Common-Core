/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:43:43 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/06 18:37:01 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "color.h"
# include "ray.h"
# include "camera.h"
# include "vec3.h"
# include "hittable_list.h"
# include "shapes.h"
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
			t_world *world,
			t_data *img
			);
t_color	ray_color(t_ray r, t_world *world, int depth);
void	write_bmp_image(
			t_image image,
			t_camera camera,
			t_world *world,
			int fd
			);
void	export_bmp(
			t_image image,
			t_camera camera,
			t_world *world,
			char	*argv
			);
int		ft_strcmp(char *str1, char *str2);
void	run_mlx(t_image image, t_camera camera, t_world *world);
double	unit_direction(t_ray r);
#endif
