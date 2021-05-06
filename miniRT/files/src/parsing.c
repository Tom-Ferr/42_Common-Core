/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:22:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/06 18:08:41 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	parse_file(
			t_image *image,
			t_settings *camera,
			t_world *world,
			char *line
		)
{
	if (line[0] == 'R')
		parse_resolution(line, image);
	else if (line[0] == 'A')
		parse_ambient(line, world);
	else if (line[0] == 'c' && line[1] == 'y')
		parse_cylinder(line, world);
	else if (line[0] == 'c')
		parse_camera(line, camera);
	else if (line[0] == 'l')
		parse_light(line, world);
	else if (line[0] == 's' && line[1] == 'p')
		parse_sphere(line, world);
	else if (line[0] == 'p' && line[1] == 'l')
		parse_plane(line, world);
	else if (line[0] == 's' && line[1] == 'q')
		parse_square(line, world);
	else if (line[0] == 't' && line[1] == 'r')
		parse_triangle(line, world);
}

void	parse_scene(
			t_image *image,
			t_settings *camera,
			t_world *world,
			char *argv
		)
{
	int		fd;
	char	*line;
	char	*src;

	src = ft_strjoin("./scenes/", argv);
	fd = open(src, O_RDONLY);
	free(src);
	while (get_next_line(fd, &line) > 0)
		parse_file(image, camera, world, line);
	free(line);
}
