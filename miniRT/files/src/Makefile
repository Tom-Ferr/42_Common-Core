# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 18:16:40 by tde-cama          #+#    #+#              #
#    Updated: 2021/04/12 14:07:38 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	vec3_ii.c vec3_i.c ray.c hittable_list.c sphere.c\
					hittable.c numbers.c camera.c vec3_iii.c vec3_iv.c\
					material.c

OBJS			= ${SRCS:.c=.o}

BONUS			=

BONUS_OBJS		= ${BONUS:.c=.o}

NAME			= libraytracing.a

GCC				=	gcc

AR				=	ar -rcs

CFLAGS			= -Wall -Wextra -Werror

.c.o:
					${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):		${OBJS}
					${AR} ${NAME} ${OBJS}

bonus:			${BONUS_OBJS} $(NAME)
					${AR} $(NAME) ${BONUS} ${BONUS_OBJS}

main:			all
				${GCC} ${CFLAGS} main.c -L. -lraytracing -o my_ppm

run:			main
				./my_ppm

noflag:			all
				${GCC} main.c -L. -lraytracing

run_noflag:		noflag
				./my_ppm

image:			main
				./my_ppm > image.ppm

open_img:		image
				open image.ppm

all:			${NAME}

clean:
					rm -f ${OBJS} ${BONUS_OBJS} image.ppm my_ppm

fclean:			clean
					rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re main run noflag run_noflag image open_img
