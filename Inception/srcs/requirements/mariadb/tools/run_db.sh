# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_db.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 22:03:22 by tde-cama          #+#    #+#              #
#    Updated: 2021/11/13 22:03:23 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


if [ $(ls /var/lib/mysql | wc -l)  -eq 0 ]
then
    /etc/init.d/mariadb setup;
    rc-service mariadb start
    mysql -u root -e "create user '$MYSQL_USER'@'%' identified by '$MYSQL_PASSWORD';\
    create database $MYSQL_DATABASE;\
    grant all privileges on *.* to '$MYSQL_USER'@'%';\
    flush privileges";
    mysql -u root $MYSQL_DATABASE < /wp-db.sql;
    mysql -u root -e "alter user 'root'@'localhost' identified by '$MYSQL_ROOT_PASSWORD'";
fi

exec /usr/bin/mysqld_safe --datadir='/var/lib/mysql'
