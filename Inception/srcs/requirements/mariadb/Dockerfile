FROM alpine:3.13
RUN apk update
RUN apk add openrc
RUN apk add mariadb mariadb-common mariadb-client
RUN openrc
RUN touch /run/openrc/softlevel
COPY ./tools/run_db.sh  /
COPY ./conf/mariadb-server.cnf /etc/my.cnf.d
EXPOSE 3306
ENTRYPOINT /bin/sh  /run_db.sh