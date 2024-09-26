CC = cc
CFLAGS = -Wall -Wextra -Werror -g -D ERROR_MESSAGES
CLIB_DIR = libft
CLIB = ft

NAME = push_swap
SRCS = main.c input.c clean.c rules.c sort.c
ALGO = adv_bubble_sort.c selection_sort.c
HEAD = push_swap.h
OBJS = $(SRCS:.c=.o) $(ALGO:.c=.o)

.PHONY: all clean fclean bclean re test ftest memleak

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(CLIB_DIR) bonus
	$(CC) -o $(NAME) $(OBJS) -L$(CLIB_DIR) -l$(CLIB)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	clear
	-./$(NAME)
	-./$(NAME) 0 one 2 3
	-./$(NAME) 42
	-./$(NAME) 42 0
	-./$(NAME) 42 100
	-./$(NAME) 42 0 1
	-./$(NAME) 42 0 100
	-./$(NAME) 42 0 1 2
	-./$(NAME) 42 0 1 100
	-./$(NAME) 42 0 1 2 3
	-./$(NAME) 42 0 1 2 100
	-./$(NAME) 42 0 84 2 100
	-./$(NAME) 42 84 0 5 2 100
	-./$(NAME) 42 84 2 100
	-./$(NAME) 17 93 46 22 50 96 11 98 32 85 | wc -l
	-./$(NAME) 0 1 2
	-./$(NAME) 0 2 1
	-./$(NAME) 1 0 2
	-./$(NAME) 1 2 0
	-./$(NAME) 2 0 1
	-./$(NAME) 2 1 0


norm:
	norminette

memleak: $(NAME)
	valgrind -s --leak-check=full --show-leak-kinds=all ./$(NAME) 42 -8 21 -2 -1 0
