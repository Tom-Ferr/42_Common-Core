/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:12:04 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/28 16:03:55 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "get_next_line.h"
# include "utils.h"

void	parse_scene(t_image *image,
			t_settings *camera,
			t_hittable_list **world
			);
void	next_number(char **param);
int		parse_int(char **param);
double	parse_double(char **param);
t_vec3	parse_coordinates(char **line);

void	parse_sphere(char *line, t_hittable_list **world);

#endif
