# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 18:16:40 by tde-cama          #+#    #+#              #
#    Updated: 2021/06/10 15:34:16 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES			= set_path.c ft_split.c free_star.c

SRCDIR			= src/

SRCS			= $(addprefix $(SRCDIR), $(FILES)) main.c

OBJS			= ${SRCS:.c=.o}

BONUS_FILES		= ft_strcmp_bonus.c get_next_line_utils_bonus.c get_next_line_bonus.c

BONUS_DIR		= bonus/

BONUS			= $(addprefix $(BONUS_DIR), $(BONUS_FILES)) $(addprefix $(SRCDIR), $(FILES))

BONUS_OBJS		= ${BONUS:.c=.o}

NAME			= pipex

GCC				=	gcc

AR				=	ar -rcs

CFLAGS			= -Wall -Wextra -Werror

INCLUDE 		= -I ./libft -I./includes


.c.o:
				${GCC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME):		${OBJS}
				${GCC} ${CFLAGS} -fsanitize=address ${OBJS} -o ${NAME}

all:			${NAME}

bonus:			${BONUS_OBJS}
				${GCC} ${CFLAGS} ${BONUS_OBJS} ${INCLUDE} ./bonus/multi_bonus.c -o $(addprefix $(NAME), _multi_bonus)
				${GCC} ${CFLAGS} ${BONUS_OBJS} ${INCLUDE} ./bonus/double_bonus.c -o $(addprefix $(NAME), _double_bonus)

clean:
				rm -f ${OBJS} ${BONUS_OBJS}

fclean:			clean
				rm -f ${NAME} pipex_multi_bonus pipex_double_bonus

re:				fclean all

.PHONY:			all clean fclean re
