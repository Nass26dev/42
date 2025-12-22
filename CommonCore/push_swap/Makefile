# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 17:20:57 by nass              #+#    #+#              #
#    Updated: 2025/01/09 08:24:19 by nyousfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = src/push_swap/creation/create_stack.c \
			src/push_swap/creation/error.c \
			src/push_swap/creation/free_launcher_one_arg.c \
			src/push_swap/creation/free_launcher.c \
			src/push_swap/creation/init_b.c \
			src/push_swap/creation/launcher.c \
			src/push_swap/rules/push.c \
			src/push_swap/rules/reverse_rotate.c \
			src/push_swap/rules/rotate.c \
			src/push_swap/rules/swap.c \
			src/push_swap/sort_cpy/rules_ww/push_ww.c \
			src/push_swap/sort_cpy/rules_ww/reverse_rotate_ww.c \
			src/push_swap/sort_cpy/rules_ww/rotate_ww.c \
			src/push_swap/sort_cpy/rules_ww/swap_ww.c \
			src/push_swap/sort_cpy/do_rotations_ww.c \
			src/push_swap/sort_cpy/sort_cpy.c \
			src/push_swap/utils/cost.c \
			src/push_swap/utils/find.c \
			src/push_swap/utils/find2.c \
			src/push_swap/utils/ft_split.c \
			src/push_swap/utils/verification.c \
			src/push_swap/do_rotations.c \
			src/push_swap/driver.c \
			src/push_swap/sort.c
			
BONUS = src/checker/create_stack.c \
			src/checker/driver.c \
			src/checker/error.c \
			src/checker/launcher.c \
			src/checker/gnl/get_next_line.c \
			src/checker/gnl/get_next_line_utils.c \
			src/checker/verification.c \
			src/checker/ft_split.c \
			src/checker/init_b.c \
			src/checker/free_launcher_one_arg.c \
			src/checker/free_launcher.c \
			src/checker/rules/push.c \
			src/checker/rules/reverse_rotate.c \
			src/checker/rules/rotate.c \
			src/checker/rules/swap.c
			
			
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

HEADER = include/push_swap/push_swap.h \
			include/push_swap/rules.h \
			include/push_swap/rules_ww.h

BONUS_HEADER = include/checker/checker.h \
					include/checker/get_next_line.h \
					include/checker/rules.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

both: all bonus

%.o: src/push_swap/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $@ -o $<

bonus%.o: src/checker/%.c $(BONUS_HEADER)
	$(CC) $(CFLAGS) -c $@ -o $<

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus both clean fclean re