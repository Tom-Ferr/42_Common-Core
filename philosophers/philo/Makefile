# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 18:16:40 by tde-cama          #+#    #+#              #
#    Updated: 2021/08/07 10:19:05 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES			= utils.c

SRCDIR			= src/

SRCS			= $(addprefix $(SRCDIR), $(FILES)) main.c

OBJS			= ${SRCS:.c=.o}

NAME			= philo

GCC				=	gcc

AR				=	ar -rcs

CFLAGS			= -Wall -Wextra -Werror

INCLUDE 		= -I./includes


.c.o:
					${GCC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME):		${OBJS}
				${GCC} ${CFLAGS} -fsanitize=address ${OBJS} -o ${NAME}

all:			${NAME}

clean:
				rm -f ${OBJS}

fclean:			clean
				rm -f ${NAME}
re:				fclean all

.PHONY:			all clean fclean re
