# /etc/init.d/mariadb setup
# rc-service mariadb start
exec /usr/bin/mysqld_safe --datadir='/var/lib/mysql'
