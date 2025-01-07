# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 17:17:21 by nass              #+#    #+#              #
#    Updated: 2025/01/07 12:15:10 by nyousfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = src/pipex.c \
		src/utils.c \
		src/utils2.c \
		src/error.c \
		src/std.c \
		src/error_utils.c \
		src/here_doc.c
			
OBJS = $(SRCS:.c=.o)

HEADER = include/pipex.h

LIBFT = include/libft
LIBFT_HEADER = include/libft/ft_printf.h \
			include/libft/get_next_line.h \
			include/libft/libft.h

INFILE = infile
OUTFILE = outfile

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)

files: $(INFILE) $(OUTFILE)

$(INFILE):
	touch $(INFILE)

$(OUTFILE):
	touch $(OUTFILE)

%.o: src/pipex/%.c $(HEADER)
	$(CC) $(CFLAGS) -I$(LIBFT_HEADER) -c $@ -o $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(INFILE)
	rm -f $(OUTFILE)

re: fclean all

.PHONY: all files clean fclean re