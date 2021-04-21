/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:15:22 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/21 18:02:37 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_point3	origin(const t_ray r)
{
	return (r.orig);
}

t_vec3	direction(const t_ray r)
{
	return (r.dir);
}

t_point3	at(const double t, const t_ray r)
{
	return (vec_add(r.orig, vec_multiply(t, r.dir)));
}

t_ray	cast_ray(t_point3 origin, t_vec3 direction)
{
	t_ray	r;

	r.orig = origin;
	r.dir = direction;
	return (r);
}
