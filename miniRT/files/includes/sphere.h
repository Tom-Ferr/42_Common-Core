/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:43:19 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/22 10:01:55 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "hittable.h"
# include "vec3.h"

typedef struct s_sphere
{
	t_hit_record	base;
	t_point3		center;
	double			radius;
	t_material		*mat_ptr;
	bool			(*hit)(t_params_list*, struct	s_sphere*);
}					t_sphere;

typedef struct s_sph
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
	t_vec3	outward_normal;
}			t_sph;

t_sphere	init_sphere(t_point3 cen, double rad, t_material *material);
bool		sphere_hit(t_params_list *params, t_sphere *obj);

#endif
