/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:27:32 by tde-cama          #+#    #+#             */
/*   Updated: 2021/03/11 14:01:54 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
char	*flags_layer(va_list args, char *format);
int		ft_atoi(const char *str);
char	*ft_dtox(size_t d, bool a);
int		ft_isdigit(int c);
int		ft_isset(char const s, char const *check);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_make_str(int n, ...);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *str);
char	*ft_strjoin_free(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*precision_layer(va_list args, char *format);
char	*print_format(va_list args, char *format, char flag);
char	*specifier_layer(va_list args, char *format);
char	*width_layer(va_list args, char *format, char flag);

#endif
