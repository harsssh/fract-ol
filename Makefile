CFLAGS=-Wall -Wextra -Werror
INCLUDE=-Ilibft -Imlx -Iinclude
SRC=$(wildcard src/lib/*.c)
HEADER=$(wildcard include/*.h)
OBJ=$(SRC:.c=.o)
MAIN=src/main.c
LIBFT=libft/libft.a
MLX=mlx/libmlx.a
NAME=fract-ol

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(MAIN) $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -Llibft -Lmlx -lft -lmlx -framework OpenGL -framework Appkit $(OBJ) $(MAIN)

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx

.PHONY: clean
clean:
	make -C libft clean
	make -C mlx clean
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
