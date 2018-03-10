ifeq ($(HOSTTYPE),)
HOSTTYPE =	$(shell uname -m)_$(shell uname -s)
endif

NAME =	libft_malloc_$(HOSTTYPE).so
LINK =	libft_malloc.so

CC =	gcc
FLAGS =	-Wall -Wextra

SRC_DIR =	src
OBJ_DIR =	.obj
INC_DIR =	include

SRC =	malloc.c show_alloc.c zone.c\
		get.c allocation.c error.c\
		free.c realloc.c realloc_2.c
OBJ =	$(SRC:%.c=$(OBJ_DIR)/%.o)
INC =	malloc.h prototypes.h structs.h

INCLUDE =	$(INC:%.h=$(INC_DIR)/%.h)

LIBFT =	libft

.PHONY: clean fclean all re norme newline $(LIBFT)/libft.so

.SILENT:

all: $(NAME)

newline:
	@echo "\033[38;5;166mft_malloc\033[0m\n"

$(LIBFT)/libft.so:
	@make -C $(LIBFT)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE) | $(OBJ_DIR)
	@echo "\033[1A\033[K\033[38;5;226mmaking $@\033[0m"
	@$(CC) $(FLAGS) -fPIC -I include -I $(LIBFT)/include -o $@ -c $<

$(NAME): $(LIBFT)/libft.so newline $(OBJ)
	@echo "\033[1A\033[K\033[38;5;214mmaking $@\033[0m"
	@$(CC) $(FLAGS) -shared -I include -I $(LIBFT)/include -o $(NAME) $(OBJ) -L $(LIBFT) -lft -lpthread
	@ln -sf $(NAME) $(LINK)
	@echo "\033[1A\033[K\033[38;5;214m$@ done\033[0m"
	@sudo cp $(NAME) $(LINK) /usr/local/lib

clean:
	@echo "\033[38;5;166mft_malloc\033[0m\n"
	@rm -f $(OBJ)
	@echo "\033[1A\033[K\033[38;5;45mobject files removed\033[0m\n"
	@make -C $(LIBFT) clean

fclean: clean
	@echo "\033[38;5;166mft_malloc\033[0m\n"
	@rm -f $(NAME) $(LINK)
	@echo "\033[1A\033[K\033[38;5;87m$(NAME) removed\033[0m\n"
	@make -C $(LIBFT) fclean

re: fclean all

norme: newline
	norminette $(OBJ:.o=.c) include
