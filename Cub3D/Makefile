# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 11:15:05 by nyousfi           #+#    #+#              #
#    Updated: 2025/11/10 09:53:39 by nyousfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT = Libft
MLX = minilibx
LIBDIR = Libft/libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD -MP -g3
MLXFLAGS = -lm -Lminilibx -lmlx -lX11 -lXext
SRCS = src/main.c \
		src/get_next_line.c \
		src/get_next_line_utils.c \
		src/utils.c \
		src/raycast.c \
		src/map.c \
		src/map_utils.c \
		src/print.c \
		src/textures.c \
		src/draw_floor_ceiling.c \
		src/parsing.c \
		src/is_here.c \
		src/is_valid.c \
		src/free.c \
		src/player.c \
		src/launch.c \
		src/movement_keypress.c \
		src/movement_keypress_utils.c \
		src/view_keypress.c \
		src/exist.c \
		src/parse_helper.c 

MAKEDIR = make
OBJDIR = make/objs
DEPDIR = make/deps

OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)
DEPS = $(SRCS:src/%.c=$(DEPDIR)/%.d)

HEADER = include/cub3D.h \
			minilibx/mlx.h \
			include/get_next_line.h

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
	
$(NAME): $(OBJS) force
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(LIBDIR) -o $(NAME)
	@$(eval COMPILED := 1)

$(OBJDIR)/%.o: src/%.c $(HEADER)
	@echo "$(MESSAGE_COLOR_YELLOW)Compiling $@... 🛠️$(MESSAGE_RESET)"
	@mkdir -p $(OBJDIR) $(DEPDIR)
	@$(CC) $(CFLAGS) -Iinclude -c $< -o $@
	@mv -f $(OBJDIR)/$*.d $(DEPDIR)/$*.d
	@$(eval COMPILED := 1)
	@echo "$(MESSAGE_COLOR_GREEN)Compilation of $@ done! ✅$(MESSAGE_RESET)"

-include $(DEPS)

force:
	@make -j -C $(LIBFT)
	@make -j -C $(MLX)

clean:
	@make clean -j -C $(LIBFT)
	@make clean -j -C $(MLX)
	@if [ -d $(MAKEDIR) ] || [ -f $(NAME) ]; then \
		rm -rf $(MAKEDIR); \
		echo "$(MESSAGE_COLOR_RED)all files are deleted 🗑️$(MESSAGE_RESET)"; \
	else \
		echo "$(MESSAGE_COLOR_GREEN)files already deleted 😉$(MESSAGE_RESET)"; \
	fi

fclean: clean
	@rm -f $(NAME)
	@make fclean -j -C $(LIBFT)

re: fclean all

.PHONY: all files clean fclean re force