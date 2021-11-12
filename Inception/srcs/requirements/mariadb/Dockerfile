FROM alpine:3.13
RUN apk update
RUN apk add mariadb mariadb-common mariadb-client
RUN apk add openrc
RUN mkdir -p /run/openrc
RUN mkdir -p /run/mysqld
RUN touch /run/openrc/softlevel
COPY ./script.sh /
RUN chmod +x /script.sh
RUN chown mysql:mysql /script.sh
RUN /etc/init.d/mariadb setup
USER mysql
# EXPOSE 3306
# CMD ["sh", "/script.sh"]