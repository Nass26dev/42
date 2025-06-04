# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 09:52:11 by nyousfi           #+#    #+#              #
#    Updated: 2025/06/04 15:04:26 by nyousfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD -MP
SRCS = src/main.c \
		src/create.c \
		src/error.c \
		src/error_utils.c \
		src/routine_utils.c \
		src/routine.c \
		src/utils.c

MAKEDIR = make
OBJDIR = make/objs
DEPDIR = make/deps

OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)
DEPS = $(SRCS:src/%.c=$(DEPDIR)/%.d)

HEADER = include/philo.h \

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
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@$(eval COMPILED := 1)

$(OBJDIR)/%.o: src/%.c $(HEADER)
	@echo "$(MESSAGE_COLOR_YELLOW)Compiling $@... 🛠️$(MESSAGE_RESET)"
	@mkdir -p $(OBJDIR) $(DEPDIR)
	@$(CC) $(CFLAGS) -Iinclude -c $< -o $@
	@mv -f $(OBJDIR)/$*.d $(DEPDIR)/$*.d
	@$(eval COMPILED := 1)
	@echo "$(MESSAGE_COLOR_GREEN)Compilation of $@ done! ✅$(MESSAGE_RESET)"

-include $(DEPS)

clean:
	@if [ -d $(MAKEDIR) ] || [ -f $(NAME) ]; then \
		rm -rf $(MAKEDIR); \
		echo "$(MESSAGE_COLOR_RED)all files are deleted 🗑️$(MESSAGE_RESET)"; \
	else \
		echo "$(MESSAGE_COLOR_GREEN)files already deleted 😉$(MESSAGE_RESET)"; \
	fi


fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all files clean fclean re