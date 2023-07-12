NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLIB		= -L $(MLX_DIR) -lmlx -framework Metal -framework Metalkit -Imlx
RM			= rm -f

LIB_DIR		= ./my_libft/
MLX_DIR		= ./mlx/
SRCS_DIR	= ./srcs/

SRCS		= so_long.c
OBJS		= $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))


all			: libs $(NAME)

libs		:
	@$(MAKE) -C $(dir $(LIB_DIR))
	@$(MAKE) -C $(dir $(MLX_DIR))
	@echo $(YELLOW) "✭	[ mlx ]		Ready to use MiniLibX" $(RESET)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) -L $(LIB_DIR) -l_jihykim2 $(MLIB)
	@install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)
	@echo $(GREEN) "⚡︎	[ fdf ]		Ready to use fdf" $(RESET)

clean	:
	@$(MAKE) -C $(dir $(LIB_DIR)) clean
	@echo $(YELLOW) "✭	[ my_libft ]	Removed Object files" $(RESET)
	@$(MAKE) -C $(dir $(MLX_DIR)) clean
	@echo $(YELLOW) "✭	[ mlx ]		Removed Object files" $(RESET)
	@$(RM) $(OBJS)
	@echo $(GREEN) "⚡︎	[ fdf ]		Removed Object files" $(RESET)

fclean	:
	@$(MAKE) clean
	@$(RM) $(LIB_DIR)lib_jihykim2.a
	@echo $(YELLOW) "✭	[ my_libft ]	Removed lib_jihykim2.a" $(RESET)
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
