/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:57:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/11 13:06:35 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	next_number(char **param)
{
	char	*line;

	line = *param;
	while (!((*line >= '0' && *line <= '9') || *line == '-') && *line)
	{
		if (!(*line == ' ' || *line == ',' || *line == 9
				|| *line == '\n' || *line == '\0'))
			error_exit("input value is bad formatted");
		line++;
	}
	*param = line;
}

double	parse_double(char **param, double min, double max, char *err_)
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
	if (!(*line == ' ' || *line == ',' || *line == 9
			|| *line == '\n' || *line == '\0'))
		error_exit("input value is bad formatted");
	*str = '\0';
	*param = line;
	ret = ft_atof(str_0);
	free(str_0);
	is_inrange(ret, min, max, err_);
	return (ret);
}

t_vec3	parse_coordinates(char **line, double min, double max, char *err_)
{
	t_vec3	ret;
	char	*check;

	ret.x = parse_double(line, min, max, err_);
	check = *line;
	if (!((check[1] >= '0' && check[1] <= '9') || check[1] == '-'))
		error_exit("input value is bad formatted");
	ret.y = parse_double(line, min, max, err_);
	check = *line;
	if (!((check[1] >= '0' && check[1] <= '9') || check[1] == '-'))
		error_exit("input value is bad formatted");
	ret.z = parse_double(line, min, max, err_);
	check = *line;
	if (!(check[1] == ' ' || check[1] == '\n' || check[1] == '\0'
			|| check[1] == 9))
		error_exit("input value is bad formatted");
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	char		*ptr;
	char		*ptr_0;

	size = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	ptr = (char *)malloc(size);
	if (!ptr)
		return (0);
	ptr_0 = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (ptr_0);
}

double	ft_atof(char *str)
{
	double	int_part;
	double	dec_part;
	double	is_neg;
	int		i;

	int_part = 0.0;
	dec_part = 0.0;
	is_neg = 1.0;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			is_neg = -1.0;
	while (*str >= '0' && *str <= '9')
		int_part = int_part * 10 + (*str++ - '0');
	i = -1;
	if (*str == '.' && *str++)
	{
		while (*str >= '0' && *str <= '9')
			dec_part += (pow(10, i--) * (*str++ - '0'));
	}
	return (is_neg * (int_part + dec_part));
}
