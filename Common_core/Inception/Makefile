SERVICES = wordpress nginx mariadb
COMPOSE_FILE = srcs/docker-compose.yml

build:
	docker compose -f $(COMPOSE_FILE) build

up:
	docker compose -f $(COMPOSE_FILE) up -d

stop:
	docker compose -f $(COMPOSE_FILE) stop

down:
	docker compose -f $(COMPOSE_FILE) down -v

clean:
	docker compose -f $(COMPOSE_FILE) down -v --rmi all

re: build up

.PHONY: build up logs stop down clean re
