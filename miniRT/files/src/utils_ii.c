/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:01:12 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/10 23:48:52 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
static void	render_camera(
							t_obj_list *pov,
							t_image image,
							t_world world,
							t_vars *vars
						)
{
	int	eqip_size;

	eqip_size = ft_lstsize(world.eqip);
	while (eqip_size--)
	{
		pov = malloc(sizeof(t_obj_list));
		pov->data.img = mlx_new_image(vars->mlx, image.width, image.height);
		pov->data.addr = mlx_get_data_addr(pov->data.img,
				&pov->data.bits_per_pixel, &pov->data.line_length,
				&pov->data.endian);
		render(image, &world, world.eqip->obj->cam, &pov->data);
		ft_lstadd_back(&vars->lst, ft_lstnew(pov));
		world.eqip = world.eqip->next;
	}
}

void	run_mlx(t_image image, t_world *world)
{
	t_vars			vars;
	t_obj_list		pov;

	vars.lst = NULL;
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, image.width, image.height,
			"tde-cama's miniRT");
	render_camera(&pov, image, *world, &vars);
	ft_freelst(world->lst);
	ft_freelst(world->eqip);
	vars.zeroth = vars.lst;
	mlx_put_image_to_window(vars.mlx, vars.mlx_win,
		vars.lst->obj->data.img, 0, 0);
	mlx_key_hook(vars.mlx_win, key_pressed, &vars);
	mlx_hook(vars.mlx_win, 17, 1L << 17, close_program, &vars);
	mlx_loop(vars.mlx);
}

double	unit_direction(t_ray r)
{
	t_vec3	uv;

	uv = unit_vector(r.dir);
	return (uv.y);
}

void	is_inrange(double t, double min, double max, char *str)
{
	if (t >= min && t <= max)
		return ;
	printf("Error: %s is out of range\n", str);
	exit(EXIT_FAILURE);
}
