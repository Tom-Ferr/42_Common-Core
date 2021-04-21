/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:48:51 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/21 18:05:59 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

t_sphere	init_sphere(t_point3 cen, double rad, t_material *material)
{
	t_sphere	o;

	o.center = cen;
	o.radius = rad;
	o.hit = sphere_hit;
	o.mat_ptr = material;
	return (o);
}

bool	sphere_hit(t_params_list *params, t_sphere *obj)
{
	t_sph	eqtn;

	eqtn.oc = vec_subtract(params->r.orig, obj->center);
	eqtn.a = length_squared(params->r.dir);
	eqtn.half_b = dot(eqtn.oc, params->r.dir);
	eqtn.c = length_squared(eqtn.oc) - (obj->radius * obj->radius);
	eqtn.discriminant = (eqtn.half_b * eqtn.half_b) - (eqtn.a * eqtn.c);
	if (eqtn.discriminant < 0)
		return (false);
	eqtn.sqrtd = sqrt(eqtn.discriminant);
	eqtn.root = (-eqtn.half_b - eqtn.sqrtd) / eqtn.a;
	if (eqtn.root < params->t_min || params->t_max < eqtn.root)
	{
		eqtn.root = (-eqtn.half_b + eqtn.sqrtd) / eqtn.a;
		if (eqtn.root < params->t_min || params->t_max < eqtn.root)
			return (false);
	}
	params->rec->t = eqtn.root;
	params->rec->p = at(params->rec->t, params->r);
	eqtn.outward_normal = vec_divide(
			obj->radius, vec_subtract(params->rec->p, obj->center));
	set_face_normal(params->r, eqtn.outward_normal, params->rec);
	params->rec->mat_ptr = obj->mat_ptr;
	return (true);
}
