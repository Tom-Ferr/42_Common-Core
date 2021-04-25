/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:52:38 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/25 00:48:39 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <camera.h>

typedef struct s_bmp_header
{
	unsigned short		type;
	unsigned int		size;
	unsigned short		reserved1;
	unsigned short		reserved2;
	unsigned int		offset;
	unsigned int		dib_header_size;
	int					width_px;
	int					height_px;
	unsigned short		num_planes;
	unsigned short		bits_per_pixel;
	unsigned int		compression;
	unsigned int		image_size_bytes;
	int					x_resolution_ppm;
	int					y_resolution_ppm;
	unsigned int		num_colors;
	unsigned int		important_colors;
}						t_bmp_header;

int				create_file(void);
t_bmp_header	set_header(t_image image);
void			write_header(int fd, t_bmp_header header);
void			write_data(int fd, int clr);

#endif
