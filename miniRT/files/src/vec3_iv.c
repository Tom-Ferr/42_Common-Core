/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_iv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:00:05 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/17 21:53:33 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

bool	near_zero(t_vec3 v)
{
    const double s = 1e-8;
    return ((v.x < s) && (v.y < s) && (v.z < s));
}

t_vec3	vec_multiply_dot(t_vec3 u, t_vec3 v)
{
	t_vec3 w;

	w.x = u.x * v.x;
	w.y = u.y * v.y;
	w.z = u.z * v.z;
	return (w);
}

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	t_vec3 ret;

	ret = vec_multiply(dot(v,n), n);
	ret = vec_multiply(2, ret);
	ret = vec_subtract(v, ret);
    return (ret);
}

t_vec3	refract(const t_vec3 uv, const t_vec3 n, double etai_over_etat)
{
	double cos_theta;
    t_vec3 r_out_perp;
    double calc;
	t_vec3 r_out_parallel;

    cos_theta = fmin(dot(vec_multiply(-1,uv), n), 1.0);
    r_out_perp =  vec_add(uv, vec_multiply(cos_theta,n));
    r_out_perp =  vec_multiply(etai_over_etat, r_out_perp);
    calc = fabs(1.0 - length_squared(r_out_perp));
	calc = -sqrt(calc);
	r_out_parallel = vec_multiply(calc, n);
    return (vec_add(r_out_perp, r_out_parallel));
}

t_vec3	random_in_unit_disk(void)
{
	int b;
	t_vec3 p;

	b = 1;
    while (b)
	{
        p = init_vec(inrange_random(-1,1), inrange_random(-1,1), 0);
        if (length_squared(p) < 1)
        	return p;
    }
	return (init_vec(0,0,0));
}
