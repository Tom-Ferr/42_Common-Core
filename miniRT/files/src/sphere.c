/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:48:51 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/05 12:30:50 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

bool	sphere_hit(t_params_list *params, t_shapes *obj)
{
	t_sph	eq;

	eq.oc = vec_subtract(params->r.orig, obj->fig.sp.center);
	eq.a = length_squared(params->r.dir);
	eq.half_b = dot(eq.oc, params->r.dir);
	eq.c = length_squared(eq.oc) - (obj->fig.sp.radius * obj->fig.sp.radius);
	eq.discriminant = (eq.half_b * eq.half_b) - (eq.a * eq.c);
	if (eq.discriminant < 0)
		return (false);
	eq.sqrtd = sqrt(eq.discriminant);
	eq.root = (-eq.half_b - eq.sqrtd) / eq.a;
	if (eq.root < params->t_min || params->t_max < eq.root)
	{
		eq.root = (-eq.half_b + eq.sqrtd) / eq.a;
		if (eq.root < params->t_min || params->t_max < eq.root)
			return (false);
	}
	params->rec->t = eq.root;
	params->rec->p = at(params->rec->t, params->r);
	eq.outward_normal = vec_divide(obj->fig.sp.radius,
			vec_subtract(params->rec->p, obj->fig.sp.center));
	set_face_normal(params->r, eq.outward_normal, params->rec);
	params->rec->mat_ptr = &(obj->material);
	return (true);
}
