NAME = so_long

CC = cc
CFLAGS = -Wextra -Werror -Wall
CLIB = -L $(MLX_DIR) -lmlx -framework Metal -framework Metalkit -Imlx

SRCS = ./main.c
OBJS = $(SRCS:%.c=%.o)

MLX_DIR = ./mlx/

#rules

all : libs $(NAME)

libs:
	make -C $(MLX_DIR)

%.o : %.c
	$(CC) -Imlx -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CLIB) $(SRCS) -o $(NAME)
#	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	make -C $(MLX_DIR) clean
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all

.PHONY: all clean fclean re libs
