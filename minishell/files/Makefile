# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 18:16:40 by tde-cama          #+#    #+#              #
#    Updated: 2021/07/13 14:01:22 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES			= gnl.c gnl_utils.c utils.c list.c history.c live_string.c non-printing.c

SRCDIR			= src/

SRCS			= $(addprefix $(SRCDIR), $(FILES)) main.c

OBJS			= ${SRCS:.c=.o}

BONUS_FILES		=	utils.c list.c inputs.c ft_push_ft_swap.c ft_rotate.c\
				errs.c get_next_line_bonus.c get_next_line_utils_bonus.c\

BONUS_DIR		= bonus/src/

BONUS_SRCS		= $(addprefix $(BONUS_DIR), $(BONUS_FILES)) bonus/main_bonus.c

BONUS_OBJS		= ${BONUS_SRCS:.c=.o}

NAME			= minishell

BONUS			= checker

GCC				= clang

AR				=	ar -rcs

CFLAGS			= -Wall -Wextra -Werror

INCLUDE 		= -I./includes


.c.o:
					${GCC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME):		${OBJS}
				${GCC} ${CFLAGS} -fsanitize=address ${OBJS} -o ${NAME}

all:			${NAME}

bonus:			${BONUS_OBJS}
				${GCC} ${CFLAGS} -fsanitize=address ${BONUS_OBJS} -o ${BONUS}

clean:
				rm -f ${OBJS} ${BONUS_OBJS}

fclean:			clean
				rm -f ${NAME} ${BONUS}
re:				fclean all

.PHONY:			all clean fclean re
