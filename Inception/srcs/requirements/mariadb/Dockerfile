# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 22:02:52 by tde-cama          #+#    #+#              #
#    Updated: 2021/11/13 22:03:00 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.13
RUN apk update
RUN apk add openrc
RUN apk add mariadb mariadb-common mariadb-client
RUN openrc
RUN touch /run/openrc/softlevel
COPY ./tools/run_db.sh  /
COPY ./conf/mariadb-server.cnf /etc/my.cnf.d
COPY ./conf/wp-db.sql /
EXPOSE 3306
ENTRYPOINT /bin/sh  /run_db.sh