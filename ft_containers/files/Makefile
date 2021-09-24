# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 15:18:41 by tde-cama          #+#    #+#              #
#    Updated: 2021/09/24 09:59:18 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FILES			=

SRCDIR			= 	src/

SRCS			= 	$(addprefix $(SRCDIR), $(FILES)) main.cpp

OBJS			= 	${SRCS:.cpp=.o}

NAME			= 	ft_containers

CXX				=	clang++

AR				=	ar -rcs

CFLAGS			= 	-Wall -Wextra -Werror -std=c++98

INCLUDE 		= 	-I./includes

SANITIZE 		= 	-fsanitize=address


%.o: %.c
				${CXX} ${CFLAGS} ${INCLUDE} -c $< -o $@

$(NAME):		${OBJS}
				${CXX} ${CFLAGS} {SANITIZE} ${OBJS} -o ${NAME}

all:			${NAME}

clean:
				rm -f ${OBJS}

fclean:			clean
				rm -f ${NAME}
re:				fclean all

.PHONY:			all clean fclean re
