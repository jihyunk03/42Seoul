NAME		= philo

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=thread -g3
RM			= rm -f

SRCS_DIR	= ./srcs/
SRCS		= philo.c \
			  init_struct.c \
			  start_philo.c routine_utils.c \
			  philo_utils.c libft_utils.c check_utils.c \
			  free_all.c error_exit.c
OBJS		= $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

all		: $(NAME)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo $(GREEN) "⚡︎	[ philo ]	Ready to use philo" $(RESET)

clean	:
	@$(RM) $(OBJS)
	@echo $(GREEN) "⚡︎	[ philo ]	Removed Object files" $(RESET)

fclean	: clean
	@$(RM) $(NAME)
	@echo $(GREEN) "⚡︎	[ philo ]	Removed philo" $(RESET)

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
