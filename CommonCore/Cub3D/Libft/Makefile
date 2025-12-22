# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 04:53:13 by marvin            #+#    #+#              #
#    Updated: 2024/11/09 04:53:13 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wextra -Wall -g3
AR = ar
HEADER = libft_h
NAME = libft.a
SRCS = ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcpy.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_calloc.c\
		ft_memcmp.c\
		ft_memmove.c\
		ft_split.c\
		ft_striteri.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strnstr.c\
		ft_print_hex.c\
		ft_print_ptr.c\
		ft_print_ultimate.c\
		ft_print_utils.c\
		ft_printf.c\
		get_next_line_utils.c\
		get_next_line.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all