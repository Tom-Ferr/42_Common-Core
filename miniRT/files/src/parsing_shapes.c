/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_shapes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:02:21 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/28 21:51:20 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parse_sphere(char *line, t_hittable_list **world)
{
	t_point3	center;
	double		diameter;
	t_color		clr;
	t_material	*material;
	t_sphere	*sph;

	center = parse_coordinates(&line);
	diameter = parse_double(&line);
	clr = vec_divide(255, parse_coordinates(&line));
	material = malloc(sizeof(t_material));
	*material = set_material(clr, NONE, NONE, lambertian);
	sph = malloc(sizeof(t_sphere));
	*sph = init_sphere(center, diameter / 2, material);
	ft_lstadd_back(world, ft_lstnew(sph));
}
