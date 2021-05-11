/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_shapes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:02:21 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/11 11:39:42 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parse_sphere(char *line, t_world *world)
{
	t_obj_list	*ol;
	t_color		clr;

	line = line + 2;
	ol = malloc(sizeof(t_obj_list));
	ol->sh.fig.sp.center = parse_coordinates(&line, LONG_MIN, LONG_MAX, "");
	ol->sh.fig.sp.radius = parse_double(&line, LONG_MIN, LONG_MAX, "") / 2;
	clr = vec_divide(255, parse_coordinates(&line, 0, 255, "sphere color"));
	ol->sh.material = set_material(clr, NONE, NONE, lambertian);
	ol->sh.hit = sphere_hit;
	ft_lstadd_back(&(world->lst), ft_lstnew(ol));
}

void	parse_plane(char *line, t_world *world)
{
	t_obj_list	*ol;
	t_color		clr;

	line = line + 2;
	ol = malloc(sizeof(t_obj_list));
	ol->sh.fig.pl.center = parse_coordinates(&line, LONG_MIN, LONG_MAX, "");
	ol->sh.fig.pl.normal = parse_coordinates(&line, -1, 1, "plane normal");
	ol->sh.fig.pl.normal = normalize(ol->sh.fig.pl.normal);
	clr = vec_divide(255, parse_coordinates(&line, 0, 255, "plane color"));
	ol->sh.material = set_material(clr, NONE, NONE, lambertian);
	ol->sh.hit = plane_hit;
	ft_lstadd_back(&(world->lst), ft_lstnew(ol));
}

void	parse_square(char *line, t_world *world)
{
	t_color		clr;
	t_obj_list	*ol;

	line = line + 2;
	ol = malloc(sizeof(t_obj_list));
	ol->sh.fig.sq.center = parse_coordinates(&line, LONG_MIN, LONG_MAX, "");
	ol->sh.fig.sq.normal = parse_coordinates(&line, -1, 1, "square normal");
	ol->sh.fig.sq.normal = normalize(ol->sh.fig.sq.normal);
	ol->sh.fig.sq.size = parse_double(&line, LONG_MIN, LONG_MAX, "");
	clr = vec_divide(255, parse_coordinates(&line, 0, 255, "square color"));
	ol->sh.material = set_material(clr, NONE, NONE, lambertian);
	ol->sh.hit = square_hit;
	ft_lstadd_back(&(world->lst), ft_lstnew(ol));
}

void	parse_triangle(char *line, t_world *world)
{
	t_obj_list	*ol;
	t_color		clr;

	line = line + 2;
	ol = malloc(sizeof(t_obj_list));
	ol->sh.fig.tr.vertex1 = parse_coordinates(&line, LONG_MIN, LONG_MAX, "");
	ol->sh.fig.tr.vertex2 = parse_coordinates(&line, LONG_MIN, LONG_MAX, "");
	ol->sh.fig.tr.vertex3 = parse_coordinates(&line, LONG_MIN, LONG_MAX, "");
	ol->sh.fig.tr.normal = vec_subtract(
			ol->sh.fig.tr.vertex2, ol->sh.fig.tr.vertex1);
	ol->sh.fig.tr.normal = cross(vec_subtract(ol->sh.fig.tr.vertex3,
				ol->sh.fig.tr.vertex1), ol->sh.fig.tr.normal);
	clr = vec_divide(255, parse_coordinates(&line, 0, 255, "triangle color"));
	ol->sh.material = set_material(clr, NONE, NONE, lambertian);
	ol->sh.hit = triangle_hit;
	ft_lstadd_back(&(world->lst), ft_lstnew(ol));
}

void	parse_cylinder(char *line, t_world *world)
{
	t_obj_list	*ol;
	t_color		clr;

	line = line + 2;
	ol = malloc(sizeof(t_obj_list));
	ol->sh.fig.cy.center = parse_coordinates(&line, LONG_MIN, LONG_MAX, "");
	ol->sh.fig.cy.normal = parse_coordinates(&line, -1, 1, "cylinder normal");
	ol->sh.fig.cy.radius = parse_double(&line, LONG_MIN, LONG_MAX, "") / 2;
	ol->sh.fig.cy.size = parse_double(&line, LONG_MIN, LONG_MAX, "");
	clr = vec_divide(255, parse_coordinates(&line, 0, 255, "cylinder color"));
	ol->sh.material = set_material(clr, NONE, NONE, lambertian);
	ol->sh.hit = cylinder_hit;
	ft_lstadd_back(&(world->lst), ft_lstnew(ol));
}
