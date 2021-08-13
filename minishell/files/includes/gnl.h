/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*   By: nfranco- <nfranco-@student.42.fr>        +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/03 19:38:25 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE 80

int		get_next_line(int fd, char **line);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		distribute(char *buf, char **current, char **next);
void	*ft_bzero(void *str, size_t n);
size_t	ft_strlen(const char *str);
int		ft_strcmp(char *str1, char *str2);

#endif
