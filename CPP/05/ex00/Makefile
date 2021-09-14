# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 18:16:40 by tde-cama          #+#    #+#              #
#    Updated: 2021/09/04 15:00:23 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp Bureaucrat.cpp

OBJS			= ${SRCS:.cpp=.o}

NAME			= bureaucrat

CC				=	clang++

AR				=	ar -rcs

CFLAGS			= -Wall -Wextra -Werror

INCLUDE 		= -I.


.c.o:
					${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME):		${OBJS}
				${CC} ${CFLAGS} -fsanitize=address ${OBJS} -o ${NAME}

all:			${NAME}

clean:
				rm -f ${OBJS}

fclean:			clean
				rm -f ${NAME}
re:				fclean all

.PHONY:			all clean fclean re
