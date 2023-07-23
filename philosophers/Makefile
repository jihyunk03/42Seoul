NAME		= philo

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIB_DIR		= ./my_libft/

SRCS_DIR	= ./srcs/
# B_SRCS_DIR	= ./bonus_srcs/

SRCS		= philo.c
# B_SRCS		=

OBJS		= $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))
# B_OBJS		= $(addprefix $(B_SRCS_DIR), $(B_SRCS:.c=.o))

# ifdef _BONUS
# 	OBJ = $(B_OBJS)
# else
# 	OBJ = $(OBJS)
# endif

all		: mylib $(NAME)

mylib	:
	@$(MAKE) -C $(LIB_DIR)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIB_DIR) -l_jihykim2
	@echo $(GREEN) "⚡︎	[ philo ]	Ready to use philo" $(RESET)

clean	:
	@$(MAKE) -C $(LIB_DIR) clean
	@echo $(YELLOW) "✭	[ my_libft ]	Removed Object files" $(RESET)
	@$(RM) $(OBJS)
	@echo $(GREEN) "⚡︎	[ philo ]	Removed Object files" $(RESET)
#	@$(RM) $(B_OBJS)

fclean	: clean
	@$(MAKE) -C $(LIB_DIR) fclean
	@echo $(YELLOW) "✭	[ my_libft ]	Removed lib_jihykim2.a" $(RESET)
	@$(RM) $(NAME)
	@echo $(GREEN) "⚡︎	[ philo ]	Removed philo" $(RESET)

re		:
	@$(MAKE) fclean
	@$(MAKE) all

# bonus:
# 	@$(MAKE) _BONUS=1 all

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
