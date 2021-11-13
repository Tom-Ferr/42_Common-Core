

#IMG	=	$(shell docker images | awk '{if(NR > 1){print $$3}} ')
DOMAIN	=	$(shell awk '/tde-cama.42.fr/{print $$2}' /etc/hosts)
DIR		=	$(shell ls | awk '/tde-cama/{print $$1}')


all:	
ifneq (${DIR},tde-cama)
	sudo mkdir -p /home/tde-cama/wp-data
	sudo mkdir -p /home/tde-cama/db-data
endif
ifneq (${DOMAIN},tde-cama.42.fr)
	echo "127.0.0.1	tde-cama.42.fr" >> /etc/hosts
endif
	docker-compose -f ./srcs/docker-compose.yml up -d --build

stop:
		docker-compose -f ./srcs/docker-compose.yml down

clean:	stop
		docker system prune -a --force

fclean:	stop
		docker system prune -a --volumes --force

re:		fclean all

wp: all
	docker exec -it wordpress sh
db: all
	docker exec -it mariadb sh
ng: all
	docker exec -it nginx sh
