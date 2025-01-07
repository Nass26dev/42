# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nass <nass@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 17:08:11 by nass              #+#    #+#              #
#    Updated: 2024/12/19 00:40:34 by nass             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc
CFLAGS =  -Wall -Werror -Wextra
LDFLAGS = -lm -Lminilibx-linux -lmlx -lX11 -lXext
SRCS = src/fdf.c \
			src/lst.c \
			src/parser.c \
			src/gnl/get_next_line.c \
			src/gnl/get_next_line_utils.c \
			src/utils.c \
			src/ft_split.c \
			src/render.c \
			src/color.c \
			src/projections.c

OBJS = $(SRCS:.c=.o)

HEADER = include/fdf.h \
			include/get_next_line.h \
			include/define.h \
			include/struct.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o: src/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $@ -o $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re