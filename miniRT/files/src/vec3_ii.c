/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_ii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:26:30 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/17 18:55:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3		vec_multiply(double t, t_vec3 v)
{
	t_vec3 w;

	w.x = t * v.x;
	w.y = t * v.y;
	w.z = t * v.z;
	return (w);
}

t_vec3		vec_divide(double t, t_vec3 v)
{
	return (vec_multiply(1 / t, v));
}

double		length(const t_vec3 v)
{
	return (sqrt(length_squared(v)));
}

double		length_squared(const t_vec3 v)
{
	return ((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

t_vec3		unit_vector(t_vec3 v)
{
    return (vec_divide(length(v), v));
}
