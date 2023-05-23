NAME = so_long

RM = rm -rf

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = 	src/main.c \
		src/char_checker.c \
		src/sprites_drawer.c \
		src/utils.c \
		src/exits.c \
		src/steps_counter.c \
		src/path_checker.c \
		src/ft_mlx.c \
		src/init_game.c \
		src/init_img.c \
		src/map_checker.c \
		src/map_reader.c \
		src/map_drawer.c \
		src/ft_move.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make all -C libft
	$(CC) $(CFLAGS) $(MLXFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make clean -C libft

re: fclean all

.PHONY: all clean fclean re
