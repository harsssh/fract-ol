CFLAGS=-Wall -Wextra -Werror
INCLUDE=-Ilibft -Imlx -Iinclude
SRC=$(wildcard src/*.c)
HEADER=$(wildcard include/*.h)
OBJ=$(SRC:.c=.o)
NAME=fract-ol

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -Lft -Lmlx -lft -lmlx -frameword OpenGL -framework Appkit $(OBJ)

libft:
	make -C libft

mlx:
	make -C mlx

.PHONY: clean
clean:
	make -C libft clean
	make -C mlx clean
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	make -C libft fclean
	make -C mlx fclean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
