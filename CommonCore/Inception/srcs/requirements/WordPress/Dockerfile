FROM debian:bullseye

RUN apt-get update && \
    apt-get install -y php php-fpm php-mysql php-curl php-gd php-mbstring php-xml php-zip wget unzip mariadb-client && \
    apt-get clean

RUN mkdir -p /var/www/html
WORKDIR /var/www/html

RUN mkdir -p /run/php

RUN wget https://wordpress.org/latest.zip -O /tmp/wordpress.zip && \
    unzip /tmp/wordpress.zip -d /tmp && \
    mv /tmp/wordpress/* /var/www/html/ && \
    rm -rf /tmp/wordpress /tmp/wordpress.zip

COPY conf/wordpress.conf /var/www/html/wp-config.php
COPY tool/wordpress.sh /wordpress.sh

EXPOSE 9000

RUN chmod +x /wordpress.sh

ENTRYPOINT ["/bin/sh", "/wordpress.sh"]