/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:53:19 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/28 21:16:34 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable_list.h"

t_params_list	set_lstparam_values(
										t_ray r,
										double t_min,
										double t_max,
										t_hit_record *hit_record
								  	)
{
	t_params_list	val;

	val.r = r;
	val.t_min = t_min;
	val.t_max = t_max;
	val.rec = hit_record;
	return (val);
}

bool	hittable_list_hit(t_params_list *params, t_hittable_list *lst)
{
	t_hit_record	temp_rec;
	bool			hit_anything;
	double			closest_so_far;
	int				lst_size;
	t_params_list	load_params;

	hit_anything = false;
	closest_so_far = params->t_max;
	lst_size = ft_lstsize(lst);
	while (lst_size--)
	{
		load_params = set_lstparam_values(params->r, params->t_min,
				closest_so_far, &temp_rec);
		if (lst->obj->hit(&load_params, lst->obj))
		{
			hit_anything = true;
			closest_so_far = load_params.rec->t;
			*(params->rec) = *(load_params.rec);
		}
		lst = lst->next;
	}
	return (hit_anything);
}
