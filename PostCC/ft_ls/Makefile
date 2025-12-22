NAME = ft_ls

CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD -MP

SRCS = srcs/main.c \
		srcs/ft_ls.c

MAKEDIR = .make
OBJDIR = .make/objs
DEPDIR = .make/deps

OBJS = $(SRCS:srcs/%.c=$(OBJDIR)/%.o)
DEPS = $(SRCS:srcs/%.c=$(DEPDIR)/%.d)

HEADER = includes/

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

$(OBJDIR)/%.o: srcs/%.c $(HEADER)
	@echo "$(MESSAGE_COLOR_YELLOW)Compiling $@... 🛠️$(MESSAGE_RESET)"
	@mkdir -p $(OBJDIR) $(DEPDIR)
	@$(CC) $(CFLAGS) -Iincludes -c $< -o $@
	@mv -f $(OBJDIR)/$*.d $(DEPDIR)/$*.d 2>/dev/null || true
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

.PHONY: all clean fclean re
