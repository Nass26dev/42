# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 17:17:21 by nass              #+#    #+#              #
#    Updated: 2025/01/24 11:40:43 by nyousfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD -MP
SRCS = src/pipex.c \
		src/utils.c \
		src/utils2.c \
		src/here_doc.c

MAKEDIR = make
OBJDIR = make/objs
DEPDIR = make/deps

OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)
DEPS = $(SRCS:src/%.c=$(DEPDIR)/%.d)

HEADER = include/pipex.h
LIBFT_HEADER = include/libft/libft.h \
					include/libft/ft_printf.h \
					include/libft/get_next_line.h
LIBFT = include/libft

INFILE = infile
OUTFILE = outfile

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)

$(OBJDIR)/%.o: src/%.c $(HEADER) $(LIBFT_HEADER)
	@mkdir -p $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) -Iinclude -I$(LIBFT) -c $< -o $@
	@mv -f $(OBJDIR)/$*.d $(DEPDIR)/$*.d

-include $(DEPS)

files: $(INFILE) $(OUTFILE)

$(INFILE):
	touch $(INFILE)
	echo "salut\nca\nva\ntoi\ntoi\ntoi" > $(INFILE)
	
$(OUTFILE):
	touch $(OUTFILE)

clean:
	rm -rf $(MAKEDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(INFILE)
	rm -f $(OUTFILE)

re: fclean all

.PHONY: all files clean fclean re