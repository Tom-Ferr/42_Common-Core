/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:48:51 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/17 18:54:22 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

t_sphere	init_sphere(t_point3 cen, double rad, t_material *material)
{
	t_sphere o;

	o.center = cen;
	o.radius = rad;
	o.hit = sphere_hit;
	o.mat_ptr = material;
	return (o);
}

bool		sphere_hit(t_params_list *params, t_sphere *obj)
{
	t_vec3 oc;
    double a;
    double half_b;
    double c;
    double discriminant;

	oc = vec_subtract(params->r.orig, obj->center);
    a = length_squared(params->r.dir);
    half_b = dot(oc, params->r.dir);
    c = length_squared(oc) - (obj->radius * obj->radius);
    discriminant = (half_b * half_b) - (a * c);
	if (discriminant < 0)
        return (false);
    double sqrtd = sqrt(discriminant);
    double root = (-half_b - sqrtd) / a;
    if (root < params->t_min || params->t_max < root)
	{
        root = (-half_b + sqrtd) / a;
        if (root < params->t_min || params->t_max < root)
            return (false);
    }
    params->rec->t = root;
    params->rec->p = at(params->rec->t, params->r);
	t_vec3 outward_normal = vec_divide(obj->radius, vec_subtract(params->rec->p, obj->center));
  	set_face_normal(params->r, outward_normal, params->rec);
	params->rec->mat_ptr = obj->mat_ptr;
	return (true);
}
