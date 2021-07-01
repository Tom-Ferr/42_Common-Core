# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 18:16:40 by tde-cama          #+#    #+#              #
#    Updated: 2021/06/28 21:43:08 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES			= utils.c list.c align.c poles.c ft_push_ft_swap.c ft_rotate.c\
				errs.c scoring.c sequenza.c

SRCDIR			= src/

SRCS			= $(addprefix $(SRCDIR), $(FILES)) main.c

OBJS			= ${SRCS:.c=.o}

BONUS_FILES		=	utils.c list.c inputs.c ft_push_ft_swap.c ft_rotate.c\
				errs.c get_next_line_bonus.c get_next_line_utils_bonus.c\

BONUS_DIR		= bonus/src/

BONUS_SRCS		= $(addprefix $(BONUS_DIR), $(BONUS_FILES)) bonus/main_bonus.c

BONUS_OBJS		= ${BONUS_SRCS:.c=.o}

NAME			= push_swap

BONUS			= checker

GCC				=	gcc

AR				=	ar -rcs

CFLAGS			= -Wall -Wextra -Werror

INCLUDE 		= -I./includes


.c.o:
					${GCC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME):		${OBJS}
				${GCC} ${CFLAGS} -fsanitize=address ${OBJS} -o ${NAME}

all:			${NAME}

bonus:			${BONUS_OBJS}
				${GCC} ${CFLAGS} ${BONUS_OBJS} -o ${BONUS}

clean:
				rm -f ${OBJS} ${BONUS_OBJS}

fclean:			clean
				rm -f ${NAME} ${BONUS}
re:				fclean all

.PHONY:			all clean fclean re
