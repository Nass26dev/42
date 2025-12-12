FROM debian:bullseye

RUN apt-get update && \
    apt-get install -y mariadb-server && \
    apt-get clean

COPY conf/init.sql /docker/-entrypoint-initdb.d/

EXPOSE 3306

CMD ["mysqld_safe"]
