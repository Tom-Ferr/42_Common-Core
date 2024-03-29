/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:59:31 by tde-cama          #+#    #+#             */
/*   Updated: 2021/05/14 18:37:54 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBX_UTILS_H
# define LIBX_UTILS_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>

# define ESC 53
# define ENTER 49

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_vars
{
	void						*mlx;
	void						*mlx_win;
	struct s_hittable_list		*lst;
	struct s_hittable_list		*zeroth;
}								t_vars;

int		close_program(void);
int		error_exit(char *error);
int		key_pressed(int keycode, t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		expose_hook(t_vars *vars);

#endif
