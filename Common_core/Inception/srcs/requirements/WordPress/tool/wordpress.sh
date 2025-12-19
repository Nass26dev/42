#!/bin/sh
set -e

cd /var/www/html

echo "Waiting for MariaDB..."
until mysqladmin ping -h"${MYSQL_HOST}" --silent; do
    sleep 1
done

if ! wp core is-installed --allow-root; then
    echo "Installing WordPress..."

    wp core install \
        --url="${DOMAIN_NAME}" \
        --title="${WP_TITLE}" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --skip-email \
        --allow-root

    wp user create \
        "${WP_USER}" \
        "${WP_USER_EMAIL}" \
        --user_pass="${WP_USER_PASSWORD}" \
        --role=author \
        --allow-root
fi

echo "Starting php-fpm..."
exec php-fpm -F
