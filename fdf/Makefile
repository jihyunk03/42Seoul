NAME	= fdf

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
AR		= ar -rcs

SRCS	= $(addprefix ./fdf_files/,
		  fdf.c \
		  map_parse.c)
OBJS	= $(SRCS:.c=.o)

LIB		= my_libft/lib_jihykim2.a
MLX		= mlx/libmlx.a

all		: $(LIB) $(MLX) $(NAME)

$(LIB)	:
	@$(MAKE) -C $(dir $(LIB))

$(MLX)	:
	@$(MAKE) -C $(dir $(MLX))

$(NAME)	: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo $(GREEN) "⚡︎	[ fdf ]		Ready to use fdf" $(RESET)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@$(MAKE) -C $(dir $(LIB)) clean
	@echo $(YELLOW) "✭	[ my_libft ]	Removed Object files" $(RESET)
	@$(MAKE) -C $(dir $(MLX)) clean
	@echo $(YELLOW) "✭	[ mlx ]		Removed Object files" $(RESET)
	@$(RM) $(OBJS)
	@echo $(GREEN) "⚡︎	[ fdf ]		Removed Object files" $(RESET)

fclean	: clean
	@$(MAKE) -C $(dir $(LIB)) fclean
	@echo $(YELLOW) "✭	[ my_libft ]	Removed lib_jihykim2.a" $(RESET)
	@$(MAKE) -C $(dir $(MLX)) clean
	@echo $(YELLOW) "✭	[ mlx ]		Removed mlx" $(RESET)
	@$(RM) $(NAME)
	@echo $(GREEN) "⚡︎	[ fdf ]		Removed fdf" $(RESET)

re		:
	@$(MAKE) fclean
	@$(MAKE) all

RESET	= "\x1b[0m"
GREY	= "\x1b[30m"
RED		= "\x1b[31m"
GREEN	= "\x1b[32m"
YELLOW	= "\x1b[33m"
BLUE	= "\x1b[34m"
PURPLE	= "\x1b[35m"
CYAN	= "\x1b[36m"
WHITE	= "\x1b[37m"

.PHONY	: all clean fclean re
