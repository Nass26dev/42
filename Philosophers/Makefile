# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nass <nass@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 11:39:14 by nass              #+#    #+#              #
#    Updated: 2024/12/26 11:40:17 by nass             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = src/philo.c
			
OBJS = $(SRCS:.c=.o)

HEADER = include/philo.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: src/push_swap/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $@ -o $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re