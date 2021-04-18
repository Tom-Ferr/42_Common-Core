/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:07:00 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/31 08:42:57 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"

typedef struct s_ray {

        t_point3 orig;
        t_vec3 dir;
}		t_ray;

t_point3 origin(const t_ray r);
t_vec3 direction(const t_ray r);
t_point3 at(const double t, const t_ray r);
t_ray cast_ray(t_point3 origin, t_vec3 direction);

#endif
