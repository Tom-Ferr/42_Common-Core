# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 18:16:40 by tde-cama          #+#    #+#              #
#    Updated: 2021/05/06 18:46:47 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES			=	vec3_ii.c vec3_i.c ray.c hittable_list.c sphere.c\
					hittable.c numbers.c camera.c vec3_iii.c vec3_iv.c\
					material.c color.c libx_utils.c utils_i.c hit.c bitmap.c\
					utils_ii.c get_next_line.c get_next_line_utils.c\
					parsing.c parsing_utils.c parsing_shapes.c light.c\
					plane.c cylinder.c parse_info.c parsing_utils_ii.c\
					polygons.c

SRCDIR			= src/

SRCS			= $(addprefix $(SRCDIR), $(FILES))

OBJS			= ${SRCS:.c=.o}

BONUS			=

BONUS_OBJS		= ${BONUS:.c=.o}

NAME			= libraytracing.a

GCC				=	gcc

AR				=	ar -rcs

CFLAGS			= -Wall -Wextra -Werror

INCLUDE 		= -I ./minilibx_opengl -I./includes

MLX				= -L ./minilibx_opengl -lmlx -framework OpenGL -framework AppKit

OUT				= miniRT


.c.o:
					${GCC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME):		${OBJS}
				${AR} ${NAME} ${OBJS}

bonus:			${BONUS_OBJS} $(NAME)
				${AR} $(NAME) ${BONUS} ${BONUS_OBJS}

main:			all
				${GCC} ${CFLAGS} ${INCLUDE} main.c -L. -lraytracing ${MLX} -o ${OUT}

run:			main
				./${OUT} sphere.rt

noflag:			all
				${GCC} ${INCLUDE} main.c -L. -lraytracing ${MLX} -o ${OUT}

run_noflag:		noflag
				./${OUT} sphere.rt

bmp:			main
				./${OUT} sphere.rt --save

all:			${NAME}

clean:
				rm -f ${OBJS} ${BONUS_OBJS} ${OUT}

fclean:			clean
				rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re main run noflag run_noflag bmp
