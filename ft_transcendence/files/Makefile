# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 18:12:12 by tde-cama          #+#    #+#              #
#    Updated: 2022/01/24 18:15:08 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



all:
	docker-compose -f ./srcs/docker-compose.yml up -d --build

stop:
		docker-compose -f ./srcs/docker-compose.yml down

clean:	stop
		docker system prune -a --force

fclean:	clean

re:		fclean all

wp: all
	docker exec -it wordpress sh
db: all
	docker exec -it mariadb sh
ng: all
	docker exec -it nginx sh