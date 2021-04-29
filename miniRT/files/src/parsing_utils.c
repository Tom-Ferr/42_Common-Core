/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:57:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/28 15:58:09 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	next_number(char **param)
{
	char	*line;

	line = *param;
	while (!((*line >= '0' && *line <= '9') || *line == '-') && *line)
		line++;
	*param = line;
}

int	parse_int(char **param)
{
	int		ret;
	char	*str;
	char	*str_0;
	char	*line;

	next_number(param);
	line = *param;
	str = (char *)malloc((4 * sizeof(char)) + 1);
	str_0 = str;
	while ((*line >= '0' && *line <= '9') || *line == '-')
		*str++ = *line++;
	*str = '\0';
	*param = line;
	ret = atoi(str_0);
	free(str_0);
	return (ret);
}

double	parse_double(char **param)
{
	double	ret;
	char	*str;
	char	*str_0;
	char	*line;

	next_number(param);
	line = *param;
	str = (char *)malloc((10 * sizeof(char)) + 1);
	str_0 = str;
	while ((*line >= '0' && *line <= '9') || *line == '.' || *line == '-')
		*str++ = *line++;
	*str = '\0';
	*param = line;
	ret = atof(str_0);
	free(str_0);
	return (ret);
}

t_vec3	parse_coordinates(char **line)
{
	t_vec3	ret;

	next_number(line);
	ret.x = parse_double(line);
	next_number(line);
	ret.y = parse_double(line);
	next_number(line);
	ret.z = parse_double(line);
	return (ret);
}
