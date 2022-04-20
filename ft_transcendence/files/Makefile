# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 18:12:12 by tde-cama          #+#    #+#              #
#    Updated: 2022/04/15 11:04:05 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



all:
	docker-compose -f ./docker-compose.yml up -d --build

stop:
		docker-compose -f ./docker-compose.yml stop

down:
	docker-compose -f ./docker-compose.yml down

clean:	down
		docker system prune -a --force

re:		clean all
