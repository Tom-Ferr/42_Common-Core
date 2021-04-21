/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:34:07 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/21 19:03:37 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include "numbers.h"

typedef struct s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

t_vec3		init_vec(double e0, double e1, double e2);
t_vec3		vec_add(t_vec3 u, t_vec3 v);
t_vec3		vec_subtract(t_vec3 u, t_vec3 v);
double		dot(t_vec3 u, t_vec3 v);
t_vec3		cross(t_vec3 u, t_vec3 v);

t_vec3		vec_multiply(double t, t_vec3 v);
t_vec3		vec_divide(double t, t_vec3 v);
double		length(const t_vec3 v);
double		length_squared(const t_vec3 v);
t_vec3		unit_vector(t_vec3 v);

t_vec3		inrange_random_vec(double min, double max);
t_vec3		random_vec(void);
t_vec3		random_in_unit_sphere(void);
t_vec3		random_unit_vector(void);
t_vec3		random_in_hemisphere(const t_vec3 normal);

bool		near_zero(t_vec3 v);
t_vec3		vec_multiply_dot(t_vec3 u, t_vec3 v);
t_vec3		reflect(t_vec3 v, t_vec3 n);
t_vec3		refract(const t_vec3 uv, const t_vec3 n, double etai_over_etat);
t_vec3		random_in_unit_disk(void);

typedef t_vec3	t_point3;
typedef t_vec3	t_color;

#endif
