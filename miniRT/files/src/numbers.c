/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:18:58 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/21 18:01:44 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers.h"

int	ft_rand(void)
{
	static int					first;
	static unsigned long int	next;

	if (!first++)
		next = (unsigned long int)&next;
	next = next * 1103515243 + 12345;
	return ((unsigned int)(next / 65536) % RAND_MAX);
}

double	random_double(void)
{
	return (ft_rand() / (RAND_MAX + 1.0));
}

double	inrange_random(double min, double max)
{
	return (min + (max - min) * random_double());
}

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

double	degrees_to_radians(double degrees)
{
	return (degrees * PI / 180.0);
}
