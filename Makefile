CFLAGS=-Wall -Wextra -Werror -Ilibft -Imlx
SRC=$(wildcard src/lib/*.c) src/main.c
OBJ=$(SRC:.c=.o)
LIBFT=libft/libft.a
MLX=mlx/libmlx.dylib
NAME=fract-ol

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -Llibft -Lmlx -lft -lmlx $(OBJ)

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx
	cp $(MLX) .

.PHONY: clean
clean:
	make -C libft clean
	make -C mlx clean
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	make -C libft fclean
	$(RM) $(NAME) libmlx.dylib

.PHONY: re
re: fclean all
