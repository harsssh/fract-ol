NAME:=fractol

LIBFT:=libft/libft.a
MLX:=mlx/libmlx.dylib

SRC_DIR=src
BUILD_DIR:=build

CFLAGS:=-Wall -Wextra -Werror -Ilibft -Imlx -I/usr/X11/include
DEPFLAGS=-MT $@ -MMD -MP -MF $(BUILD_DIR)/$*.d

SRC:=src/args.c src/handler.c src/julia.c src/lib/canvas.c src/lib/color.c src/lib/complex.c src/lib/draw.c src/lib/hook.c src/lib/util.c src/main.c src/mandelbrot.c src/util.c
OBJ:=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
DEP:=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.d,$(SRC))

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) -Llibft -Lmlx -lft -lmlx -lm -o $@ $(OBJ)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(BUILD_DIR)/%.d | $(BUILD_DIR) $(BUILD_DIR)/lib
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) -c -o $@ $<

$(DEP):

$(BUILD_DIR) $(BUILD_DIR)/lib:
	@mkdir -p $@

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx
	cp $(MLX) .

.PHONY: clean
clean:
	make -C libft clean
	make -C mlx clean
	$(RM) $(OBJ) $(DEP)

.PHONY: fclean
fclean: clean
	make -C libft fclean
	$(RM) $(NAME) libmlx.dylib

.PHONY: re
re: fclean all

ifneq ($(MAKECMDGOALS),clean)
-include $(DEP)
endif
