# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 18:16:40 by tde-cama          #+#    #+#              #
#    Updated: 2021/02/15 13:12:15 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
					ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c\
					ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
					ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
					ft_split.c ft_strchr.c ft_strncmp.c ft_strdup.c ft_strjoin.c\
					ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strnstr.c\
					ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJS			= ${SRCS:.c=.o}

BONUS			= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
				  ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS		= ${BONUS:.c=.o}

NAME			= libft.a

GCC				=	gcc

AR				=	ar -rcs

CFLAGS			= -Wall -Wextra -Werror

.c.o:
					${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):		${OBJS}
					${AR} ${NAME} ${OBJS}

bonus:			${BONUS_OBJS} $(NAME)
					${AR} $(NAME) ${BONUS} ${BONUS_OBJS}


all:			${NAME}

clean:
					rm -f ${OBJS} ${BONUS_OBJS}

fclean:			clean
					rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
