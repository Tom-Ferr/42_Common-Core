# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 18:16:40 by tde-cama          #+#    #+#              #
#    Updated: 2021/09/17 13:59:33 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp Cat.cpp Dog.cpp Animal.cpp \
					WrongCat.cpp WrongDog.cpp WrongAnimal.cpp

OBJS			= ${SRCS:.cpp=.o}

NAME			= animals

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
