NAME = so_long

CC = cc
CFLAGS = -Wextra -Werror -Wall
CLIB = -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit -Imlx

SRCS = ./main.c
OBJS = $(SRCS:%.c=%.o)

MLX_DIR = ./mlx/

#rules

all : libs $(NAME)

libs:
	make -C ./mlx/

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all

.PHONY: all clean fclean re libs
