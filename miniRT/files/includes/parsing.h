/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:12:04 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/06 18:05:07 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "get_next_line.h"
# include "utils.h"

void	parse_scene(t_image *image,
			t_settings *camera,
			t_world *world,
			char *argv
			);
void	next_number(char **param);
int		parse_int(char **param);
double	parse_double(char **param);
t_vec3	parse_coordinates(char **line);

void	parse_resolution(char *line, t_image *image);
void	parse_camera(char *line, t_settings *camera);
void	parse_ambient(char *line, t_world *world);
void	parse_light(char *line, t_world *world);

void	parse_sphere(char *line, t_world *world);
void	parse_plane(char *line, t_world *world);
void	parse_triangle(char *line, t_world *world);
void	parse_square(char *line, t_world *world);
void	parse_cylinder(char *line, t_world *world);

char	*ft_strjoin(char const *s1, char const *s2);

#endif
