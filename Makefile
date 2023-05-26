NAME = so_long

SRCS = 	src/main.c \
		src/char_checker.c \
		src/path_checker.c \
		src/sprites_drawer.c \
		src/utils.c \
		src/exits.c \
		src/steps_counter.c \
		src/ft_mlx.c \
		src/init_game.c \
		src/init_img.c \
		src/map_checker.c \
		src/map_reader.c \
		src/map_drawer.c \
		src/ft_move.c

OBJS 	= $(SRCS:.c=.o)

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

.c.o:		%.o : %.c
	@${CC} ${CFLAGS} -Imlx -c $< -o $@

all: 		$(NAME)

$(NAME):	$(OBJS)
	make re -C ./libft
	$(CC) $(OBJS) $(MLXFLAGS) -Llibft -lft -o $(NAME)


bonus:		$(OBJS_B)
	rm -f $(OBJS)
	make re -C ./libft
	$(CC) $(OBJS_B) -Llibft -lft -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS) $(OBJS_B)

fclean: 	clean
	make fclean -C ./libft
	rm -f $(NAME)

re:			fclean all

re_bonus:	all clean fclean re bonus