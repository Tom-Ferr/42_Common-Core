/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:23:38 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/28 13:35:49 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBERS_H
# define NUMBERS_H

# include <limits.h>
# include <stdlib.h>
# include <math.h>

# define MY_INFINITY LONG_MAX
# define PI 3.1415926535897932385
# define NONE 0
# define FT_RAND_MAX INT_MAX
# define MAX_DEPTH 50
# define SAMPLES_PER_PIXEL 100

double	random_double(void);
double	inrange_random(double min, double max);
double	clamp(double x, double min, double max);
double	ft_fmin(double x, double y);
double	degrees_to_radians(double degrees);

#endif
