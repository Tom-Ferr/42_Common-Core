# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 22:04:40 by tde-cama          #+#    #+#              #
#    Updated: 2021/11/13 22:04:42 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#IMG	=	$(shell docker images | awk '{if(NR > 1){print $$3}} ')
DOMAIN	=	$(shell awk '/tde-cama.42.fr/{print $$2}' /etc/hosts)


all:
	sudo mkdir -p /home/tde-cama/wp-data /home/tde-cama/db-data
ifneq (${DOMAIN},tde-cama.42.fr)
	echo "127.0.0.1	tde-cama.42.fr" >> /etc/hosts
endif
	docker-compose -f ./srcs/docker-compose.yml up -d --build

stop:
		docker-compose -f ./srcs/docker-compose.yml down

clean:	stop
		docker system prune -a --force

fclean:	clean
		sudo rm -fr /home/tde-cama/

re:		fclean all

wp: all
	docker exec -it wordpress sh
db: all
	docker exec -it mariadb sh
ng: all
	docker exec -it nginx sh
