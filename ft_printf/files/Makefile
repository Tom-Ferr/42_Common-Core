# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 18:16:40 by tde-cama          #+#    #+#              #
#    Updated: 2021/03/09 14:48:50 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	utils/flags_layer.c utils/ft_atoi.c utils/ft_dtox.c\
					utils/ft_isdigit.c utils/ft_isset.c utils/ft_itoa.c\
					utils/ft_make_str.c utils/ft_memcpy.c utils/ft_memset.c\
					utils/ft_putchar_fd.c utils/ft_puthex.c utils/ft_putstr_fd.c\
					utils/ft_strdup.c utils/ft_strjoin_free.c utils/ft_strlcpy.c\
					utils/ft_strlen.c utils/precision_layer.c utils/ft_utoa.c\
					utils/specifier_layer.c utils/width_layer.c\
					utils/print_format.c\
					ft_printf.c

OBJS			= ${SRCS:.c=.o}

BONUS			=

BONUS_OBJS		= ${BONUS:.c=.o}

NAME			= libftprintf.a

GCC				=	gcc

AR				=	ar -rcs

CFLAGS			= -Wall -Wextra -Werror

.c.o:
					${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):		${OBJS}
					${AR} ${NAME} ${OBJS}

bonus:			${BONUS_OBJS} $(NAME)
					${AR} $(NAME) ${BONUS} ${BONUS_OBJS}


all:			${NAME}

clean:
					rm -f ${OBJS} ${BONUS_OBJS}

fclean:			clean
					rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
