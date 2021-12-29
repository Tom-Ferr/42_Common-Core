# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 18:00:07 by tde-cama          #+#    #+#              #
#    Updated: 2021/12/28 21:04:13 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FILES			=	accept.cpp bind.cpp listen.cpp socket.cpp request_parser.cpp requested_file.cpp\
					response.cpp config.cpp cgi.cpp server.cpp poll.cpp

SRCDIR			= 	src/

SRCS			= 	$(addprefix $(SRCDIR), $(FILES)) main.cpp

OBJS			= 	${SRCS:.cpp=.o}

HEADS			=	accept.hpp bind.hpp listen.hpp socket.hpp requested_file.hpp\
					response.hpp config.hpp cgi.hpp server.hpp poll.hpp

INC				= 	./includes/

DEPS			= 	$(addprefix ${INC}, $(HEADS))

NAME			= 	webserv

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

$(NAME):		${OBJS} $(DEPS)
				${CXX} ${CXXFLAGS} ${SANITIZE} ${OBJS} ${INCLUDE} -o ${NAME}

all:			${NAME}

clean:
				rm -f ${OBJS}

fclean:			clean
				rm -f ${NAME}
re:				fclean all

.PHONY:			all clean fclean re
