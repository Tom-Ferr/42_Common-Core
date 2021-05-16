/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:20:14 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/12 23:39:27 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

bool	plane_hit(t_params_list *params, t_shapes *obj)
{
	t_point3	oc;

	oc = vec_subtract(obj->fig.pl.center, params->r.orig);
	params->rec->t = dot(params->r.dir, obj->fig.pl.normal);
	if (!params->rec->t)
		return (false);
	params->rec->t = dot(oc, obj->fig.pl.normal) / params->rec->t;
	if (params->rec->t < params->t_min || params->t_max < params->rec->t)
		return (false);
	params->rec->p = at(params->rec->t, params->r);
	params->rec->normal = obj->fig.pl.normal;
	params->rec->mat_ptr = &(obj->material);
	return (true);
}
