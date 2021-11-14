# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 22:04:06 by tde-cama          #+#    #+#              #
#    Updated: 2021/11/13 22:04:10 by tde-cama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.13
RUN apk update
RUN apk add  php7 php7-fpm php7-common php7-pecl-redis php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom
COPY ./conf/www.conf /etc/php7/php-fpm.d/www.conf
WORKDIR /var/www/localhost/htdocs
EXPOSE 9000
COPY ./conf/wp-config.php /
COPY ./tools/run_wp.sh /
COPY ./tools/script.sh /
ENTRYPOINT ["sh", "/run_wp.sh"]
