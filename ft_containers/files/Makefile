# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 15:18:41 by tde-cama          #+#    #+#              #
#    Updated: 2021/10/25 09:33:09 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FILES			=	exception.cpp

SRCDIR			= 	src/

SRCS			= 	$(addprefix $(SRCDIR), $(FILES))

OBJS			= 	${SRCS:.cpp=.o}

HEADS			=	algorithm.hpp exception.hpp iterator.hpp map.hpp set.hpp\
					stack.hpp utility.hpp vector.hpp type_traits.hpp iterator_traits.hpp\
					random_access_iterator.hpp set_iterator.hpp map_iterator.hpp \
					reverse_iterator.hpp vector_test.cpp stack_test.cpp map_test.cpp\
					set_test.cpp

INC				= 	./includes/

DEPS			= 	$(addprefix ${INC}, $(HEADS))

MAIN			=	main.cpp

NAME			= 	ft_containers

SEED			=	$(shell date +%s)

CXX				=	clang++

AR				=	ar -rcs

CXXFLAGS		= 	-g -Wall -Wextra -Werror -std=c++98

INCLUDE 		= 	-I${INC}

SANITIZE 		= 	-fsanitize=address

UNAME			=	$(shell uname)

LINUX			= -D _LINUX

ifeq ($(UNAME),Linux)
	CXXFLAGS += $(LINUX)
endif

%.o: %.cpp		
				${CXX} ${CXXFLAGS} ${INCLUDE} -c $< -o $@

$(NAME):		${OBJS} $(DEPS) ${MAIN}
				${CXX} ${CXXFLAGS} ${SANITIZE} ${OBJS} ${INCLUDE} ${MAIN} -o ${NAME}
				${CXX} ${CXXFLAGS} ${SANITIZE} ${OBJS} -D _STL ${INCLUDE} ${MAIN} -o ${NAME}_stl

all:			${NAME}

test:			all
				./${NAME} ${SEED} > my.log
				./${NAME}_stl ${SEED} > real.log

clean:
				rm -f ${OBJS}

fclean:			clean
				rm -f ${NAME} ${NAME}_stl *.log
re:				fclean all

.PHONY:			all clean fclean re
