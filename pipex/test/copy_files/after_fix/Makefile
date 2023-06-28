NAME		= pipex

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar -rcs

INC_DIR		= ./includes/
SRCS_DIR	= ./srcs/
LIB_DIR		= ./my_libft/

SRCS		= pipex.c \
			  init_pipe.c \
			  multi_process.c \
			  split_command.c split_command_utils.c \
			  execute_command.c \
			  free_all.c error_exit.c

OBJS		= $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

all		: mylib $(NAME)

mylib	:
	@$(MAKE) -C $(LIB_DIR)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIB_DIR) -l_jihykim2 -o $(NAME)
	@echo $(GREEN) "⚡︎	[ pipex ]	Ready to use pipex" $(RESET)

clean	:
	@$(MAKE) -C $(LIB_DIR) clean
	@echo $(YELLOW) "✭	[ my_libft ]	Removed Object files" $(RESET)
	@$(RM) $(OBJS)
	@echo $(GREEN) "⚡︎	[ pipex ]	Removed Object files" $(RESET)

fclean	: clean
	@$(MAKE) -C $(LIB_DIR) fclean
	@echo $(YELLOW) "✭	[ my_libft ]	Removed lib_jihykim2.a" $(RESET)
	@$(RM) $(NAME)
	@echo $(GREEN) "⚡︎	[ pipex ]	Removed fdf" $(RESET)

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
