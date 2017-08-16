ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
NAME = libft_malloc_$(HOSTTYPE).so
LINK = libft_malloc.so
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft
SRC = malloc.c allocation.c show_alloc.c free.c sort.c malloc_error.c
OBJ = $(SRC:%.c=src/%.o)

.PHONY: clean fclean all re norme newline $(LIBFT)/libft.so

all: $(NAME)

newline:
	@echo "\033[38;5;166mft_malloc\033[0m\n"

$(LIBFT)/libft.so:
	@make -C $(LIBFT)

%.o: %.c
	@echo "\033[1A\033[K\033[38;5;226mmaking $@\033[0m"
	@$(CC) $(FLAGS) -fPIC -I include -I $(LIBFT)/include -o $@ -c $<

$(NAME): $(LIBFT)/libft.so newline $(OBJ)
	@echo "\033[1A\033[K\033[38;5;214mmaking $@\033[0m"
	@$(CC) $(FLAGS) -shared -I include -I $(LIBFT)/include -o $(NAME) $(OBJ) -L $(LIBFT) -lft -lpthread
	@ln -sf $(NAME) $(LINK)
	@sudo cp $(NAME) $(LINK) /usr/local/lib
	@echo "\033[1A\033[K\033[38;5;214m$@ done\033[0m"

clean:
	@echo "\033[38;5;166mft_malloc\033[0m\n"
	@rm -f $(OBJ)
	@echo "\033[1A\033[K\033[38;5;45mobject files removed\033[0m\n"
	@make -C $(LIBFT) clean

fclean: clean
	@echo "\033[38;5;166mft_malloc\033[0m\n"
	@rm -f $(NAME)
	@echo "\033[1A\033[K\033[38;5;87m$(NAME) removed\033[0m\n"
	@make -C $(LIBFT) fclean

re: fclean all

norme: newline
	norminette $(OBJ:.o=.c) include
