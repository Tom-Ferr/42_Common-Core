/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:22:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/11 13:07:13 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parse_resolution(char *line, t_image *image)
{
	line = line + 1;
	if (image->width || image->height)
		error_exit("Resolution can only be declared once in the scene");
	image->width = (int)parse_double(&line, 1, LONG_MAX, "Resolution Width");
	image->height = (int)parse_double(&line, 1, LONG_MAX, "Resolution Height");
	image->aspect_ratio = (double)image->width / (double)image->height;
}

void	parse_camera(char *line, t_world *world, t_image *image)
{
	t_obj_list	*ol;
	t_settings	set;

	line = line + 1;
	if (!image->width || !image->height)
		error_exit("Resolution was not declared");
	ol = malloc(sizeof(t_obj_list));
	set.lookfrom = parse_coordinates(&line, LONG_MIN, LONG_MAX, "");
	set.lookat = parse_coordinates(&line, -1, 1, "camera orientation");
	set.vfov = parse_double(&line, 0, 180, "field of view");
	set.vup = init_vec(0, 1, 0);
	set.focus_dist = length(vec_subtract(
				set.lookfrom, set.lookat));
	set.aperture = 0;
	ol->cam = set_camera(image->aspect_ratio, set);
	ft_lstadd_back(&(world->eqip), ft_lstnew(ol));
}

void	parse_ambient(char *line, t_world *world)
{
	line = line + 1;
	if (world->ambient_ratio >= 0)
		error_exit("Ambient Light can only be declared once in the scene");
	world->ambient_ratio = parse_double(&line, 0, 1, "ambient lighting ratio");
	world->ambient_light = vec_divide(255, parse_coordinates(&line, 0, 255,
				"ambient light color"));
}

void	parse_light(char *line, t_world *world)
{
	double		brightness;
	t_color		clr;
	t_obj_list	*light;

	line = line + 1;
	light = malloc(sizeof(t_obj_list));
	light->sh.fig.sp.center = parse_coordinates(&line, LONG_MIN, LONG_MAX, "");
	light->sh.fig.sp.radius = 0.35;
	brightness = parse_double(&line, 0, 1, "brightness");
	clr = vec_divide(63.75, parse_coordinates(&line, 0, 255, "light color"));
	clr = vec_multiply(brightness, clr);
	light->sh.material = set_material(clr, NONE, NONE, emissive);
	light->sh.hit = sphere_hit;
	ft_lstadd_back(&(world->lst), ft_lstnew(light));
}
