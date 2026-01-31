NAME = bin/fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

LIBDIR = ./libft/
LIB = ./libft/lib/libft.a
MINILIBX = ./minilibx-linux/

SRC = src/fractol.c \
			src/graphics.c
			
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	mkdir -p bin
	make -C $(LIBDIR)
	$(CC) $(OBJ) $(LIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ)
	make clean -C $(LIBDIR)

fclean: clean
	rm -rf bin
	make fclean -C $(LIBDIR)

bin: all clean

re: fclean all
