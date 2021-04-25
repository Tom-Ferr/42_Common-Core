/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:01:25 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/25 11:08:26 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static int	create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int	write_color(t_color pixel_color, int samples_per_pixel)
{
	int		r;
	int		g;
	int		b;
	double	scale;
	t_color	double_rgb;

	scale = 1.0 / samples_per_pixel;
	double_rgb.x = sqrt(scale * pixel_color.x);
	double_rgb.y = sqrt(scale * pixel_color.y);
	double_rgb.z = sqrt(scale * pixel_color.z);
	r = (256 * clamp(double_rgb.x, 0.0, 0.999));
	g = (256 * clamp(double_rgb.y, 0.0, 0.999));
	b = (256 * clamp(double_rgb.z, 0.0, 0.999));
	return (create_argb(0, r, g, b));
}
