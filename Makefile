CFLAGS=-Wall -Wextra -Werror -Ilibft -Imlx -Iinclude
SRC=$(wildcard src/lib/*.c)
HEADER=$(wildcard include/*.h)
OBJ=$(SRC:.c=.o)
MAIN=src/main.c
LIBFT=libft/libft.a
MLX=mlx/libmlx.dylib
NAME=fract-ol

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(MAIN) $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -Llibft -Lmlx -lft -lmlx $(OBJ) $(MAIN)

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
