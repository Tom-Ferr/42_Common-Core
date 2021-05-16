/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:22:56 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/14 18:44:50 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ext_filter(char **str)
{
	char	*fil;

	fil = *str;
	while (*fil)
	{
		if (*fil++ == '.')
		{
			if (*fil == 'r' && *(fil + 1) == 't' && *(fil + 2) == '\0')
				*(--fil) = '\0';
			else
				error_exit("Not a .rt file");
		}
	}
}

static void	get_resolution(t_image *image, char **argv)
{
	int		fd;
	char	*line;
	char	*src;
	char	*ext;

	ext_filter(argv);
	src = ft_strjoin("./scenes/", *argv);
	ext = ft_strjoin(src, ".rt");
	free(src);
	fd = open(ext, 0);
	free(ext);
	if (fd < 0)
		error_exit(".rt file not found");
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'R')
			parse_resolution(line, image);
		free(line);
	}
	free(line);
}

static void	parse_file(
			t_image *image,
			t_world *world,
			char *line
		)
{
	if (line[0] == 'A')
		parse_ambient(line, world);
	else if (line[0] == 'c' && line[1] == 'y')
		parse_cylinder(line, world);
	else if (line[0] == 'c')
		parse_camera(line, world, image);
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
	else if (!(line[0] == '\n' || line[0] == '\0' || line[0] == 'R'))
		error_exit("Bad identifier");
}

static void	errors_ifs(t_image *image, t_world *world)
{
	if (!world->lst)
		error_exit("No elements to render");
	if (!image->width || !image->height)
		error_exit("Resolution was not declared");
	if (!world->eqip)
		error_exit("Camera was not declared");
	if (world->ambient_ratio < 0)
		error_exit("Ambient Light was not declared");
}

void	parse_scene(
			t_image *image,
			t_world *world,
			char *argv
		)
{
	int		fd;
	char	*line;
	char	*src;
	char	*ext;

	get_resolution(image, &argv);
	src = ft_strjoin("./scenes/", argv);
	ext = ft_strjoin(src, ".rt");
	free(src);
	fd = open(ext, 0);
	free(ext);
	if (fd < 0)
		error_exit(".rt file not found");
	world->ambient_ratio = -1;
	while (get_next_line(fd, &line) > 0)
	{
		parse_file(image, world, line);
		free(line);
	}
	parse_file(image, world, line);
	free(line);
	errors_ifs(image, world);
}
