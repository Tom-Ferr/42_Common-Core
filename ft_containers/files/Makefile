# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 15:18:41 by tde-cama          #+#    #+#              #
#    Updated: 2021/10/08 13:59:31 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FILES			=	exception.cpp

SRCDIR			= 	src/

SRCS			= 	$(addprefix $(SRCDIR), $(FILES))

OBJS			= 	${SRCS:.cpp=.o}

NAME			= 	ft_containers

CXX				=	clang++

AR				=	ar -rcs

CXXFLAGS		= 	-g -Wall -Wextra -Werror -std=c++98

INCLUDE 		= 	-I./includes

SANITIZE 		= 	-fsanitize=address

%.o: %.cpp
				${CXX} ${CXXFLAGS} ${INCLUDE} -c $< -o $@

$(NAME):		${OBJS}
				${CXX} ${CXXFLAGS} ${SANITIZE} ${OBJS} -D _STL=0 ${INCLUDE} test.cpp -o ${NAME}
				${CXX} ${CXXFLAGS} ${SANITIZE} ${OBJS} -D _STL=1 ${INCLUDE} test.cpp -o ${NAME}_stl

all:			${NAME}

test:			all
				./${NAME} > my.log
				./${NAME}_stl > real.log

clean:
				rm -f ${OBJS}

fclean:			clean
				rm -f ${NAME} ${NAME}_stl my.log real.log
re:				fclean all

.PHONY:			all clean fclean re
