/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:22:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/28 23:45:51 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	parse_resolution(char *line, t_image *image)
{
	static int		dim;

	image->width = parse_int(&line);
	image->height = parse_int(&line);
	image->aspect_ratio = (double)image->width / (double)image->height;
	dim++;
}

static void	parse_camera(char *line, t_settings *camera)
{
	camera->lookfrom = parse_coordinates(&line);
	camera->lookat = parse_coordinates(&line);
	camera->vfov = parse_double(&line);
	camera->vup = init_vec(0, 1, 0);
	camera->focus_dist = length(vec_subtract(camera->lookfrom, camera->lookat));
	camera->aperture = 0;
}

// static void	parse_ambient(char *line, t_ambient *ambient)
// {
// 	ambient->ratio = parse_double(&line);
// 	ambient->color = parse_coordinates(&line);
// }

// static void	parse_light(char *line, t_hittable_list **world)
// {
// 	t_point3	point;
// 	double		brightness;
// 	t_color		clr;
// 	t_material	*material;
// 	t_sphere	*light;
//
// 	point = parse_coordinates(&line);
// 	brightness = parse_double(&line);
// 	clr = vec_divide(255, parse_coordinates(&line));
// 	material = malloc(sizeof(t_material));
// 	*material = set_material(clr, NONE, NONE, lambertian);
// 	light = malloc(sizeof(t_sphere));
// 	*light = init_sphere(position, diameter / 2, material);
// 	ft_lstadd_back(world, ft_lstnew(sph));
// }

void	parse_scene(
			t_image *image,
			t_settings *camera,
			t_hittable_list **world
		)
{
	int		fd;
	char	*line;

	fd = open("./scenes/sphere.rt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'R')
			parse_resolution(line, image);
		// else if (line[0] == 'A')
		// 	parse_ambient();
		else if (line[0] == 'c')
			parse_camera(line, camera);
		// else if (line[0] == 'l')n
		// 	parse_light();
		else if (line[0] == 's' && line[1] == 'p')
			parse_sphere(line, world);
	}
	free(line);
}
