# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 14:11:48 by nyousfi           #+#    #+#              #
#    Updated: 2024/08/27 20:10:50 by nyousfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./includes

SRCS = srcs/ft_putchar.c \
	 srcs/ft_putstr.c \
	 srcs/ft_strcmp.c \
	 srcs/ft_strlen.c \
	 srcs/ft_swap.c

NAME = libft.a

OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
