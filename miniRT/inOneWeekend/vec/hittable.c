/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:35:57 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/14 12:47:31 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"

void set_face_normal(const t_ray r, const t_vec3 outward_normal, t_hit_record *h)
{
	h->front_face = dot(r.dir, outward_normal) < 0;
	if (h->front_face)
	 	h->normal = outward_normal;
	else
		h->normal = vec_multiply(-1, outward_normal);
}
