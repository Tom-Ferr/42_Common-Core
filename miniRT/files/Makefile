# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 18:16:40 by tde-cama          #+#    #+#              #
#    Updated: 2021/05/15 19:22:40 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES			=	vec3_ii.c vec3_i.c ray.c hittable_list.c sphere.c\
					hittable.c numbers.c camera.c vec3_iii.c vec3_iv.c\
					material.c color.c libx_utils.c utils_i.c hit.c bitmap.c\
					utils_ii.c get_next_line.c get_next_line_utils.c\
					parsing.c parsing_utils.c parsing_shapes.c light.c\
					plane.c cylinder.c parse_info.c polygons.c\

SRCDIR			= src/

SRCS			= $(addprefix $(SRCDIR), $(FILES)) main.c

OBJS			= ${SRCS:.c=.o}

BONUS			=

BONUS_OBJS		= ${BONUS:.c=.o}

NAME			= miniRT

GCC				=	gcc

AR				=	ar -rcs

CFLAGS			= -Wall -Wextra -Werror

INCLUDE 		= -I ./minilibx_opengl -I./includes

MLX				= -L ./minilibx_opengl -lmlx -framework OpenGL -framework AppKit


.c.o:
					${GCC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME):		${OBJS}
				make -C minilibx_opengl
				${GCC} ${CFLAGS} -fsanitize=address ${OBJS} ${MLX} -o ${NAME}

all:			${NAME}

clean:
				rm -f ${OBJS}

fclean:			clean
				rm -f ${NAME}
				make clean -C minilibx_opengl
re:				fclean all

.PHONY:			all clean fclean re
