/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:55:45 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/05 23:06:03 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"
#include "hittable_list.h"

static bool	cylinder_equation(
								t_params_list *params,
								t_shapes *obj,
								t_sph *eqtn,
								double t[]
							)
{
	t_vec3	v;
	t_vec3	u;

	v = vec_multiply(dot(obj->fig.cy.normal, params->r.dir),
			obj->fig.cy.normal);
	v = vec_subtract(params->r.dir, v);
	eqtn->oc = vec_subtract(params->r.orig, obj->fig.cy.center);
	u = vec_multiply(dot(eqtn->oc, obj->fig.cy.normal), obj->fig.cy.normal);
	u = vec_subtract(eqtn->oc, u);
	eqtn->a = length_squared(v);
	eqtn->half_b = dot(v, u);
	eqtn->c = dot(u, u) - (obj->fig.cy.radius * obj->fig.cy.radius);
	eqtn->discriminant = (eqtn->half_b * eqtn->half_b) - (eqtn->a * eqtn->c);
	if (eqtn->discriminant < 0)
		return (false);
	eqtn->sqrtd = sqrt(eqtn->discriminant);
	t[0] = (-eqtn->half_b - eqtn->sqrtd) / eqtn->a;
	t[1] = (-eqtn->half_b + eqtn->sqrtd) / eqtn->a;
	return (true);
}

static bool	define_t(
								t_params_list *params,
								t_shapes *obj,
								t_sph *eqtn,
								double t[]
							)
{
	t_vec3	dist0;
	double	dist1;

	eqtn->oc = vec_subtract(obj->fig.cy.center, params->r.orig);
	dist0 = vec_subtract(vec_multiply(t[0], params->r.dir), eqtn->oc);
	dist1 = dot(obj->fig.cy.normal, dist0);
	if (!(dist1 >= 0 && dist1 <= obj->fig.cy.size))
	{
		dist0 = vec_subtract(vec_multiply(t[1], params->r.dir), eqtn->oc);
		dist1 = dot(obj->fig.cy.normal, dist0);
		if (!(dist1 >= 0 && dist1 <= obj->fig.cy.size))
			return (false);
		eqtn->root = t[1];
	}
	else
		eqtn->root = t[0];
	if (eqtn->root < params->t_min || params->t_max < eqtn->root)
		return (false);
	params->rec->t = eqtn->root;
	params->rec->p = at(params->rec->t, params->r);
	eqtn->outward_normal = vec_add(vec_multiply(dist1, obj->fig.cy.normal),
			obj->fig.cy.center);
	eqtn->outward_normal = normalize(vec_subtract(params->rec->p,
				eqtn->outward_normal));
	return (true);
}

bool	cylinder_hit(t_params_list *params, t_shapes *obj)
{
	t_sph	eqtn;
	double	t[2];

	if (!cylinder_equation(params, obj, &eqtn, t))
		return (false);
	if (!define_t(params, obj, &eqtn, t))
		return (false);
	set_face_normal(params->r, eqtn.outward_normal, params->rec);
	params->rec->mat_ptr = &(obj->material);
	return (true);
}
