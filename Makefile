NAME = bin/fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O3 #-fsanitize=address

LIBDIR = ./libft/
LIB = ./libft/lib/libft.a
MINILIBX = ./minilibx-linux/

SRC = src/main.c \
	  src/fractal.c \
	  src/zoom.c \
	  src/keyboard.c \
	  src/change_const.c \
	  src/utils.c \
	  src/malloc_mlx.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	mkdir -p bin
	make -C $(LIBDIR)
	make -C $(MINILIBX)
	$(CC) $(OBJ) $(LIB) -Lminilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ)
	make clean -C $(MINILIBX)
	make clean -C $(LIBDIR)

fclean: clean
	rm -rf bin
	make fclean -C $(LIBDIR)

bin: all clean

re: fclean all
