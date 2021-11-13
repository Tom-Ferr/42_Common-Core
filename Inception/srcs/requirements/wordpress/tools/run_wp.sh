if [ $(ls | wc -l) -eq 0 ]
then
    wget http://wordpress.org/latest.tar.gz
    tar -xzvf latest.tar.gz
    mv ./wordpress/* .
    rm -fr wordpress
    rm -f latest.tar.gz
    mv /wp-config.php .
fi
exec /usr/sbin/php-fpm7 --nodaemonize