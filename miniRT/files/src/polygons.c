/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:20:14 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/06 19:40:14 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

static bool	inside_outside(t_params_list *params, t_triangle or, t_triangle tr)
{
	t_vec3	c1;
	t_vec3	c2;
	t_vec3	c3;

	c1 = vec_subtract(params->rec->p, or.vertex1);
	c2 = vec_subtract(params->rec->p, or.vertex2);
	c3 = vec_subtract(params->rec->p, or.vertex3);
	return (dot(params->rec->normal, cross(tr.vertex1, c1)) < 0
		&& dot(params->rec->normal, cross(tr.vertex2, c2)) < 0
		&& dot(params->rec->normal, cross(tr.vertex3, c3)) < 0
	);
}

static t_triangle	vectorize(t_triangle tr)
{
	t_triangle	vec;

	vec.vertex1 = vec_subtract(tr.vertex2, tr.vertex1);
	vec.vertex2 = vec_subtract(tr.vertex3, tr.vertex2);
	vec.vertex3 = vec_subtract(tr.vertex1, tr.vertex3);
	return (vec);
}

static void	make_vertices(t_point3 *vertices, t_shapes *obj)
{
	t_vec3	width;
	t_vec3	height;

	width = cross(obj->fig.sq.normal, init_vec(
				obj->fig.sq.normal.z, obj->fig.sq.normal.x, obj->fig.sq.normal.y
				));
	height = cross(obj->fig.sq.normal, width);
	width = vec_multiply(obj->fig.sq.size / 2, width);
	height = vec_multiply(obj->fig.sq.size / 2, height);
	vertices[0] = vec_add(vec_add(obj->fig.sq.center, width), height);
	vertices[1] = vec_subtract(vec_add(obj->fig.sq.center, width), height);
	vertices[2] = vec_subtract(vec_subtract(obj->fig.sq.center, width), height);
	vertices[3] = vec_add(vec_subtract(obj->fig.sq.center, width), height);
}

bool	triangle_hit(t_params_list *params, t_shapes *obj)
{
	t_triangle	tr;

	if (!plane_hit(params, obj))
		return (false);
	tr = vectorize(obj->fig.tr);
	if (inside_outside(params, obj->fig.tr, tr))
		return (true);
	return (false);
}

bool	square_hit(t_params_list *params, t_shapes *obj)
{
	t_point3	*vertices;
	t_triangle	or1;
	t_triangle	or2;
	t_triangle	sq1;
	t_triangle	sq2;

	if (!plane_hit(params, obj))
		return (false);
	vertices = malloc(4 * sizeof(t_point3));
	make_vertices(vertices, obj);
	or1.vertex1 = vertices[0];
	or1.vertex2 = vertices[1];
	or1.vertex3 = vertices[2];
	or2.vertex1 = vertices[0];
	or2.vertex2 = vertices[2];
	or2.vertex3 = vertices[3];
	sq1 = vectorize(or1);
	sq2 = vectorize(or2);
	free(vertices);
	if (inside_outside(params, or1, sq1))
		return (true);
	if (inside_outside(params, or2, sq2))
		return (true);
	return (false);
}
