/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:43:33 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/13 23:43:45 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "vec3.h"
# include "numbers.h"

void write_color(t_color pixel_color, int samples_per_pixel)
{
    int r;
    int g;
    int b;
	double scale = 1.0 / samples_per_pixel;
	double rd = pixel_color.x;
	double gd = pixel_color.y;
	double bd = pixel_color.z;

    rd = sqrt(scale * rd);
    gd = sqrt(scale * gd);
    bd = sqrt(scale * bd);

	r = (256 * clamp(rd, 0.0, 0.999));
    g = (256 * clamp(gd, 0.0, 0.999));
    b = (256 * clamp(bd, 0.0, 0.999));
	printf("%i %i %i\n", r, g, b);
}

#endif
