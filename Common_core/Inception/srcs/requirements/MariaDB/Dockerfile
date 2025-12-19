FROM debian:bullseye

RUN mkdir -p /run/mysqld && chmod 777 /run/mysqld

RUN apt-get update && \
    apt-get install -y mariadb-server && \
    apt-get clean

COPY conf/mariadb.conf /docker-entrypoint-initdb.d/
COPY tool/mariadb.sh /

EXPOSE 3306

RUN chmod +x /mariadb.sh

ENTRYPOINT ["/bin/sh", "/mariadb.sh"]
