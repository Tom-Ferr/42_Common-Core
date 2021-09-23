# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 18:16:40 by tde-cama          #+#    #+#              #
#    Updated: 2021/09/16 13:50:42 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJS			= ${SRCS:.cpp=.o}

NAME			= fragtrap

CC				=	clang++

AR				=	ar -rcs

CFLAGS			= -Wall -Wextra -Werror -std=c++98

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
