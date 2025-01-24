# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 17:17:21 by nass              #+#    #+#              #
#    Updated: 2025/01/24 14:35:22 by nyousfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD -MP
SRCS = src/pipex.c \
		src/pipex_utils.c \
		src/secure.c \
		src/here_doc.c \
		src/creation_utils.c

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

COMPILED = 0
MESSAGE_COLOR_GREEN = \033[1;32m
MESSAGE_COLOR_BLUE = \033[1;34m
MESSAGE_COLOR_YELLOW = \033[1;33m
MESSAGE_COLOR_RED = \033[1;31m
MESSAGE_RESET = \033[1;0m

all: $(NAME)
	@if [ $(COMPILED) -eq 1 ]; then \
		echo "$(MESSAGE_COLOR_BLUE)compilation done 🎉$(MESSAGE_RESET)"; \
	else \
		echo "$(MESSAGE_COLOR_BLUE)everything is already up to date 😉$(MESSAGE_RESET)"; \
	fi
	
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)
	@$(eval COMPILED := 1)

$(OBJDIR)/%.o: src/%.c $(HEADER) $(LIBFT_HEADER)
	@echo "$(MESSAGE_COLOR_YELLOW)Compiling $@... 🛠️$(MESSAGE_RESET)"
	@mkdir -p $(OBJDIR) $(DEPDIR)
	@$(CC) $(CFLAGS) -Iinclude -I$(LIBFT) -c $< -o $@
	@mv -f $(OBJDIR)/$*.d $(DEPDIR)/$*.d
	@$(eval COMPILED := 1)
	@echo "$(MESSAGE_COLOR_GREEN)Compilation of $@ done! ✅$(MESSAGE_RESET)"

-include $(DEPS)

files:
	@if [ ! -f $(INFILE) ] || [ ! -f $(OUTFILE) ]; then \
		touch $(INFILE); \
		echo "salut\nca\nva\ntoi\ntoi\ntoi" > $(INFILE); \
		touch $(OUTFILE); \
		echo "$(MESSAGE_COLOR_GREEN)the test files have been created 📄$(MESSAGE_RESET)"; \
	else \
		echo "$(MESSAGE_COLOR_BLUE)the test files already exist 😉$(MESSAGE_RESET)"; \
	fi

clean:
	@if [ -d $(MAKEDIR) ] || [ -f $(NAME) ]; then \
		rm -rf $(MAKEDIR); \
		rm -f $(NAME); \
		echo "$(MESSAGE_COLOR_RED)all files are deleted 🗑️$(MESSAGE_RESET)"; \
	else \
		echo "$(MESSAGE_COLOR_GREEN)files already deleted 😉$(MESSAGE_RESET)"; \
	fi


fclean: clean
	@rm -f $(NAME)
	@if [ -f $(INFILE) ] || [ -f $(OUTFILE) ]; then \
		rm -f $(INFILE); \
		rm -f $(OUTFILE); \
		echo "$(MESSAGE_COLOR_YELLOW)Test files removed successfully 🧹$(MESSAGE_RESET)"; \
	fi
	@rm -f $(INFILE)
	@rm -f $(OUTFILE)

re: fclean all

.PHONY: all files clean fclean re