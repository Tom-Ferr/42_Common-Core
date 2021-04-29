/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:39:43 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/28 23:46:10 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_image			image;
	t_camera		camera;
	t_hittable_list	*world;
	t_settings		settings;

	parse_scene(&image, &settings, &world);
	camera = set_camera(image.aspect_ratio, settings);
	if (ft_strcmp(argv[argc - 1], "--save"))
		run_mlx(image, camera, world);
	else
		export_bmp(image, camera, world);
}
