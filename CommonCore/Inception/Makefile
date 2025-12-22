SERVICES = wordpress nginx mariadb
COMPOSE_FILE = srcs/docker-compose.yml

build:
	docker compose -f $(COMPOSE_FILE) build

up:
	docker compose -f $(COMPOSE_FILE) up -d

logs:
	docker compose -f $(COMPOSE_FILE) logs -f

stop:
	docker compose -f $(COMPOSE_FILE) stop

down:
	docker compose -f $(COMPOSE_FILE) down -v

clean:
	docker compose -f $(COMPOSE_FILE) down -v --rmi all

re: clean build up

.PHONY: build up logs stop down clean re

# todo: 

# chmod 777 /home/nyousfi/data/mariadb /home/nyousfi/data/wordpress
# sudo rm -rf /home/nyousfi/data/mariadb/* /home/nyousfi/data/wordpress/*



# mkdir -p /home/nyousfi/data/mariadb/ /home/nyousfi/data/wordpress/