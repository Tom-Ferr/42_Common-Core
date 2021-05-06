/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:43:19 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/06 18:43:29 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "hittable.h"
# include "vec3.h"

typedef struct s_sphere
{
	t_point3		center;
	double			radius;
}					t_sphere;

typedef struct s_triangle
{
	t_point3		vertex1;
	t_point3		vertex2;
	t_point3		vertex3;
	t_point3		normal;
}					t_triangle;

typedef struct s_plane
{
	t_point3		center;
	t_point3		normal;
}					t_plane;

typedef struct s_square
{
	t_point3		center;
	t_point3		normal;
	double			size;
}					t_square;

typedef struct s_cylinder
{
	t_point3		center;
	t_point3		normal;
	double			radius;
	double			size;
}					t_cylinder;

typedef union u_figures
{
	t_sphere		sp;
	t_plane			pl;
	t_triangle		tr;
	t_square		sq;
	t_cylinder		cy;
}					t_figures;

typedef struct s_shapes
{
	t_material		material;
	bool			(*hit)(t_params_list*, struct	s_shapes*);
	t_figures		fig;
}					t_shapes;

typedef struct s_sph
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
	t_vec3	outward_normal;
}			t_sph;

bool		sphere_hit(t_params_list *params, t_shapes *obj);
bool		plane_hit(t_params_list *params, t_shapes *obj);
bool		triangle_hit(t_params_list *params, t_shapes *obj);
bool		square_hit(t_params_list *params, t_shapes *obj);
bool		cylinder_hit(t_params_list *params, t_shapes *obj);

#endif
