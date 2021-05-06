/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:22:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/06 17:54:31 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parse_resolution(char *line, t_image *image)
{
	static int		dim;

	image->width = parse_int(&line);
	image->height = parse_int(&line);
	image->aspect_ratio = (double)image->width / (double)image->height;
	dim++;
}

void	parse_camera(char *line, t_settings *camera)
{
	camera->lookfrom = parse_coordinates(&line);
	camera->lookat = parse_coordinates(&line);
	camera->vfov = parse_double(&line);
	camera->vup = init_vec(0, 1, 0);
	camera->focus_dist = length(vec_subtract(camera->lookfrom, camera->lookat));
	camera->aperture = 0;
}

void	parse_ambient(char *line, t_world *world)
{
	world->ambient_ratio = parse_double(&line);
	world->ambient_light = vec_divide(255, parse_coordinates(&line));
}

void	parse_light(char *line, t_world *world)
{
	double		brightness;
	t_color		clr;
	t_shapes	*light;

	light = malloc(sizeof(t_shapes));
	light->fig.sp.center = parse_coordinates(&line);
	light->fig.sp.radius = 0.35;
	brightness = parse_double(&line);
	clr = vec_divide(63.75, parse_coordinates(&line));
	clr = vec_multiply(brightness, clr);
	light->material = set_material(clr, NONE, NONE, emissive);
	light->hit = sphere_hit;
	ft_lstadd_back(&(world->lst), ft_lstnew(light));
}
