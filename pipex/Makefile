NAME		= pipex

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIB_DIR		= ./my_libft/

SRCS_DIR	= ./srcs/
B_SRCS_DIR	= ./bonus_srcs/

SRCS		= pipex.c \
			  init_pipe.c \
			  multi_process.c \
			  split_command.c split_command_utils.c \
			  execute_command.c \
			  free_all.c error_exit.c
B_SRCS		= pipex_bonus.c \
			  init_pipe_bonus.c \
			  multi_process_bonus.c \
			  split_command_bonus.c split_command_utils_bonus.c \
			  execute_command_bonus.c \
			  free_all_bonus.c error_exit_bonus.c

OBJS		= $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))
B_OBJS		= $(addprefix $(B_SRCS_DIR), $(B_SRCS:.c=.o))

ifdef _BONUS
	OBJ = $(B_OBJS)
else
	OBJ = $(OBJS)
endif

all		: $(NAME)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJ)
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIB_DIR) -l_jihykim2
	@echo $(GREEN) "⚡︎	[ pipex ]	Ready to use pipex" $(RESET)

clean	:
	@$(MAKE) -C $(LIB_DIR) clean
	@echo $(YELLOW) "✭	[ my_libft ]	Removed Object files" $(RESET)
	@$(RM) $(OBJS)
	@$(RM) $(B_OBJS)
	@echo $(GREEN) "⚡︎	[ pipex ]	Removed Object files" $(RESET)

fclean	: clean
	@$(MAKE) -C $(LIB_DIR) fclean
	@echo $(YELLOW) "✭	[ my_libft ]	Removed lib_jihykim2.a" $(RESET)
	@$(RM) $(NAME)
	@echo $(GREEN) "⚡︎	[ pipex ]	Removed pipex" $(RESET)

re		:
	@$(MAKE) fclean
	@$(MAKE) all

bonus:
	@$(MAKE) _BONUS=1 all

.PHONY	: all clean fclean re bonus

RESET	= "\x1b[0m"
GREY	= "\x1b[30m"
RED		= "\x1b[31m"
GREEN	= "\x1b[32m"
YELLOW	= "\x1b[33m"
BLUE	= "\x1b[34m"
PURPLE	= "\x1b[35m"
CYAN	= "\x1b[36m"
WHITE	= "\x1b[37m"
