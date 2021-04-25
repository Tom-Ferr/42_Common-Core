/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:49:17 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/25 13:09:00 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

int	create_file(void)
{
	int		fd;

	fd = open("./saves/test.bmp", O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR);
	return (fd);
}

t_bmp_header	set_header(t_image image)
{
	t_bmp_header	header;
	int				sizeof_header;

	sizeof_header = 54;
	header.type = 0x4d42;
	header.size = (image.width * image.height) + sizeof_header;
	header.reserved1 = 0;
	header.reserved2 = 0;
	header.offset = sizeof_header;
	header.dib_header_size = 40;
	header.width_px = image.width;
	header.height_px = image.height;
	header.num_planes = 1;
	header.bits_per_pixel = 32;
	header.compression = 0;
	header.image_size_bytes = header.size - sizeof_header;
	header.x_resolution_ppm = 2835;
	header.y_resolution_ppm = 2835;
	header.num_colors = 0;
	header.important_colors = 0;
	return (header);
}

void	write_header(int fd, t_bmp_header header)
{
	write(fd, &header.type, 2);
	write(fd, &header.size, 4);
	write(fd, &header.reserved1, 2);
	write(fd, &header.reserved2, 2);
	write(fd, &header.offset, 4);
	write(fd, &header.dib_header_size, 4);
	write(fd, &header.width_px, 4);
	write(fd, &header.height_px, 4);
	write(fd, &header.num_planes, 2);
	write(fd, &header.bits_per_pixel, 2);
	write(fd, &header.compression, 4);
	write(fd, &header.image_size_bytes, 4);
	write(fd, &header.x_resolution_ppm, 4);
	write(fd, &header.y_resolution_ppm, 4);
	write(fd, &header.num_colors, 4);
	write(fd, &header.important_colors, 4);
}

void	write_data(int fd, int clr)
{
	unsigned char	to_write;

	to_write = clr & 255;
	write(fd, &to_write, sizeof to_write);
	to_write = (clr & (255 << 8)) >> 8;
	write(fd, &to_write, sizeof to_write);
	to_write = (clr & (255 << 16)) >> 16;
	write(fd, &to_write, sizeof to_write);
	to_write = 0;
	write(fd, &to_write, sizeof to_write);
}
