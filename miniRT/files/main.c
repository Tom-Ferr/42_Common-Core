/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:39:43 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/10 18:04:05 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_image			image;
	//t_camera		camera;
	t_world			world;

	world.lst = NULL;
	world.eqip = NULL;
	if (!(argc <= 3 && argc > 1))
		error_exit("Wrong number of arguments");
	parse_scene(&image, &world, argv[1]);
	// camera = set_camera(image.aspect_ratio, settings);
	if (argc != 3)
		run_mlx(image, &world);
	else if (!ft_strcmp(argv[2], "--save"))
		export_bmp(image, &world, argv[1]);
	else
		error_exit("second argument is not --save");

}
