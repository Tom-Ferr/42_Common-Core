/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_iii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:42:15 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/14 16:55:50 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "numbers.h"

t_vec3 random_vec()
{
	return init_vec(random_double(), random_double(), random_double());
}

t_vec3 inrange_random_vec(double min, double max)
{
	return init_vec(inrange_random(min,max), inrange_random(min,max),
	inrange_random(min,max));
}

t_vec3 random_in_unit_sphere()
{	int b;

	b = 1;
    while (b)
	{
        t_point3 p = inrange_random_vec(-1.0,1.0);
        if (length_squared(p) < 1.0)
        	return (p);
    }
	return (init_vec(0,0,0));
}

t_vec3 random_unit_vector()
{
    return (unit_vector(random_in_unit_sphere()));
}

t_vec3 random_in_hemisphere(const t_vec3 normal)
{
    t_vec3 in_unit_sphere = random_in_unit_sphere();
    if (dot(in_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return in_unit_sphere;
    else
        return vec_multiply(-1, in_unit_sphere);
}
