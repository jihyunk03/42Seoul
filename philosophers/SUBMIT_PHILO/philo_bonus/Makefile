NAME		= philo_bonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRCS_DIR	= ./srcs/
SRCS		= philo_0_bonus.c \
			  philo_1_init_bonus.c \
			  philo_2_child_process_bonus.c \
			  philo_2_parent_process_bonus.c \
			  get_time_utils_bonus.c \
			  message_print_bonus.c \
			  free_and_exit_bonus.c \
			  libft_utils_bonus.c \
			  libft_utils_2_bonus.c
OBJS		= $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

ifdef BONUS
	OBJ = $(OBJS)
else
	OBJ = $(OBJS)
endif

all		:
	@$(MAKE) $(NAME)

bonus	:
	@$(MAKE) BONUS=1 $(NAME)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo $(GREEN) "⚡︎	[ philo_bonus ]	Ready to use philo_bonus" $(RESET)

clean	:
	@$(RM) $(OBJS)
	@echo $(GREEN) "⚡︎	[ philo_bonus ]	Removed Object files" $(RESET)

fclean	: clean
	@$(RM) $(NAME)
	@echo $(GREEN) "⚡︎	[ philo_bonus ]	Removed philo_bonus" $(RESET)

re		:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY	: all clean fclean re

RESET	= "\x1b[0m"
GREY	= "\x1b[30m"
RED		= "\x1b[31m"
GREEN	= "\x1b[32m"
YELLOW	= "\x1b[33m"
BLUE	= "\x1b[34m"
PURPLE	= "\x1b[35m"
CYAN	= "\x1b[36m"
WHITE	= "\x1b[37m"
