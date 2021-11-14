# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_wp.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 22:03:59 by tde-cama          #+#    #+#              #
#    Updated: 2021/11/13 22:04:00 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if [ $(ls | wc -l) -eq 0 ]
then
    wget http://wordpress.org/latest.tar.gz
    tar -xzvf latest.tar.gz
    mv ./wordpress/* .
    rm -fr wordpress
    rm -f latest.tar.gz
    sh /script.sh > /wpconfig
    mv /wpconfig ./wp-config.php
fi
exec /usr/sbin/php-fpm7 --nodaemonize