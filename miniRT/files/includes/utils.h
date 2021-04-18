/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:43:43 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/18 10:54:28 by tde-cama         ###   ########.fr       */
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

void	render(t_image image, t_camera camera, t_hittable_list *world, t_data *img);
t_color ray_color(t_ray r, t_hittable_list *world, int depth);

#endif
