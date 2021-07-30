# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 18:16:40 by tde-cama          #+#    #+#              #
#    Updated: 2021/07/30 14:24:01 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES			= gnl.c gnl_utils.c utils.c utils_2.c list.c history.c \
				inputs.c keys.c ft_export.c ft_split.c ft_strncmp.c ft_unset.c\
				parsing.c artolst.c live_string.c pipe.c utils_3.c \
				pipex.c pipex_2.c utils_4.c builtins.c ft_strnstr.c utils_5.c \
				quotes.c heredoc.c

SRCDIR			= src/

SRCS			= $(addprefix $(SRCDIR), $(FILES)) main.c

OBJS			= ${SRCS:.c=.o}

NAME			= minishell

GCC				= clang

AR				= ar -rcs

CFLAGS			= -g -Wall -Wextra -Werror

INCLUDE 		= -I./includes


.c.o:
					${GCC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME):		${OBJS}
				${GCC} ${CFLAGS} -fsanitize=address ${OBJS} -o ${NAME}

all:			${NAME}

clean:
				rm -f ${OBJS}

fclean:			clean
				rm -f ${NAME} .history.log

re:				fclean all

.PHONY:			all clean fclean re
