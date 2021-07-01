/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:09:52 by tde-cama          #+#    #+#             */
/*   Updated: 2021/06/10 13:33:28 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "pipex.h"

# define BUFFER_SIZE 80

int		get_next_line(int fd, char **line);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		distribute(char *buf, char **current, char **next);
void	*ft_bzero(void *str, size_t n);
size_t	ft_strlen(const char *str);
int		ft_strcmp(char *str1, char *str2);

#endif
