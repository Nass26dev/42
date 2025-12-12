FROM debian:bullseye

RUN apt-get update && \
    apt-get install -y php php-fpm php-mysql php-curl php-gd php-mbstring php-xml php-zip wget unzip && \
    apt-get clean

RUN mkdir -p /var/www/html
WORKDIR /var/www/html

RUN wget https://wordpress.org/latest.zip -O /tmp/wordpress.zip && \
    unzip /tmp/wordpress.zip -d /tmp && \
    mv /tmp/wordpress/* /var/www/html/ && \
    rm -rf /tmp/wordpress /tmp/wordpress.zip

COPY conf/wp-config.php /var/www/html/wp-config.php

EXPOSE 9000

CMD ["php-fpm7.4", "-F"]