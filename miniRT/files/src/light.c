/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:10:23 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/29 23:20:33 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

bool	emissive(
					t_ray r_in,
					struct s_hit_record rec,
					t_color *attenuation,
					t_ray *scattered
				)
{
	r_in = *scattered;
	rec.p = *attenuation;
	*scattered = r_in;
	*attenuation = rec.p;
	return (false);
}

t_color	emitted(t_material *material)
{
	if (material->scatter == emissive)
		return (material->albedo);
	else
		return (init_vec(0, 0, 0));
}
