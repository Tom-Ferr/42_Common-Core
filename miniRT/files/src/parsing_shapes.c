/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_shapes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:02:21 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/06 19:24:35 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parse_sphere(char *line, t_world *world)
{
	t_shapes	*sh;
	t_color		clr;

	sh = malloc(sizeof(t_shapes));
	sh->fig.sp.center = parse_coordinates(&line);
	sh->fig.sp.radius = parse_double(&line) / 2;
	clr = vec_divide(255, parse_coordinates(&line));
	sh->material = set_material(clr, NONE, NONE, lambertian);
	sh->hit = sphere_hit;
	ft_lstadd_back(&(world->lst), ft_lstnew(sh));
}

void	parse_plane(char *line, t_world *world)
{
	t_shapes	*sh;
	t_color		clr;

	sh = malloc(sizeof(t_shapes));
	sh->fig.pl.center = parse_coordinates(&line);
	sh->fig.pl.normal = parse_coordinates(&line);
	sh->fig.pl.normal = normalize(sh->fig.pl.normal);
	clr = vec_divide(255, parse_coordinates(&line));
	sh->material = set_material(clr, NONE, NONE, lambertian);
	sh->hit = plane_hit;
	ft_lstadd_back(&(world->lst), ft_lstnew(sh));
}

void	parse_square(char *line, t_world *world)
{
	t_color		clr;
	t_shapes	*sh;

	sh = malloc(sizeof(t_shapes));
	sh->fig.sq.center = parse_coordinates(&line);
	sh->fig.sq.normal = parse_coordinates(&line);
	sh->fig.sq.normal = normalize(sh->fig.sq.normal);
	sh->fig.sq.size = parse_double(&line);
	clr = vec_divide(255, parse_coordinates(&line));
	sh->material = set_material(clr, NONE, NONE, lambertian);
	sh->hit = square_hit;
	ft_lstadd_back(&(world->lst), ft_lstnew(sh));
}

void	parse_triangle(char *line, t_world *world)
{
	t_shapes	*sh;
	t_color		clr;

	sh = malloc(sizeof(t_shapes));
	sh->fig.tr.vertex1 = parse_coordinates(&line);
	sh->fig.tr.vertex2 = parse_coordinates(&line);
	sh->fig.tr.vertex3 = parse_coordinates(&line);
	sh->fig.tr.normal = vec_subtract(sh->fig.tr.vertex2, sh->fig.tr.vertex1);
	sh->fig.tr.normal = cross(vec_subtract(sh->fig.tr.vertex3,
				sh->fig.tr.vertex1), sh->fig.tr.normal);
	clr = vec_divide(255, parse_coordinates(&line));
	sh->material = set_material(clr, NONE, NONE, lambertian);
	sh->hit = triangle_hit;
	ft_lstadd_back(&(world->lst), ft_lstnew(sh));
}

void	parse_cylinder(char *line, t_world *world)
{
	t_shapes	*sh;
	t_color		clr;

	sh = malloc(sizeof(t_shapes));
	sh->fig.cy.center = parse_coordinates(&line);
	sh->fig.cy.normal = parse_coordinates(&line);
	sh->fig.cy.radius = parse_double(&line) / 2;
	sh->fig.cy.size = parse_double(&line);
	clr = vec_divide(255, parse_coordinates(&line));
	sh->material = set_material(clr, NONE, NONE, lambertian);
	sh->hit = cylinder_hit;
	ft_lstadd_back(&(world->lst), ft_lstnew(sh));
}
