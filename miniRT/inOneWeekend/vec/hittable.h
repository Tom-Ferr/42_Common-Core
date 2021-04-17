/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:15:30 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/12 14:20:04 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

# include "ray.h"
# include <stdbool.h>
# include "material.h"


typedef struct s_params_list
{
	t_ray r;
	double t_min;
	double t_max;
	t_hit_record *rec;
}				t_params_list;


void set_face_normal(const t_ray r, const t_vec3 outward_normal, t_hit_record *h);
#endif
