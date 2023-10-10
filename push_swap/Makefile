NAME	= push_swap
BONUS	= checker

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
AR		= ar -rcs

LIB_DIR	= ./my_libft/

P_DIR	= ./push_swap_files/
SRCS	= $(P_DIR)push_swap.c \
		  $(P_DIR)free_all.c \
		  $(P_DIR)stack_init.c \
		  $(P_DIR)stack_init_utils.c \
		  $(P_DIR)short_sort.c \
		  $(P_DIR)op_swap.c \
		  $(P_DIR)op_push.c \
		  $(P_DIR)op_rotate.c \
		  $(P_DIR)op_rv_rotate.c \
		  $(P_DIR)check_stack.c \
		  $(P_DIR)a_sort_to_b.c \
		  $(P_DIR)b_sort_to_a.c
OBJS	= $(SRCS:.c=.o)
INCD	= $(P_DIR)push_swap.h \
		  $(P_DIR)struct_info.h \
		  $(P_DIR)define_enum.h

B_DIR	= ./checker_files/
B_SRCS	= $(B_DIR)checker.c \
		  $(B_DIR)free_all.c \
		  $(B_DIR)stack_init.c \
		  $(B_DIR)stack_init_utils.c \
		  $(B_DIR)op_swap.c \
		  $(B_DIR)op_push.c \
		  $(B_DIR)op_rotate.c \
		  $(B_DIR)op_rv_rotate.c \
		  $(B_DIR)check_stack.c
B_OBJS	= $(B_SRCS:.c=.o)
B_INCD	= $(B_DIR)checker.h \
		  $(B_DIR)struct_info.h \
		  $(B_DIR)define_enum.h

all		: $(LIB) $(NAME)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIB_DIR) -l_jihykim2
	@echo $(GREEN) "⚡︎ [ push_swap ]	Ready to use push_swap" $(RESET)

clean	:
	@$(MAKE) -C $(LIB_DIR) clean
	@echo $(YELLOW) "✭  [ my_libft ]	Removed Object files" $(RESET)
	@$(RM) $(OBJS) $(B_OBJS)
	@echo $(GREEN) "⚡︎ [ push_swap ]	Removed Object files" $(RESET)

fclean	: clean
	@$(MAKE) -C $(LIB_DIR) fclean
	@echo $(YELLOW) "✭  [ my_libft ]	Removed lib_jihykim2.a" $(RESET)
	@$(RM) $(NAME) $(BONUS)
	@echo $(GREEN) "⚡︎ [ push_swap ]	Removed push_swap" $(RESET)
	@echo $(GREEN) "⚡︎ [ checker ]		Removed checker" $(RESET)

re		:
	@$(MAKE) fclean
	@$(MAKE) all

bonus	: $(BONUS)

$(BONUS): $(B_OBJS)
	@$(CC) $(CFLAGS) -o $(BONUS) $(B_OBJS) -L$(LIB_DIR) -l_jihykim2
	@echo $(GREEN) "⚡︎ [ checker ]		Ready to use checker" $(RESET)

RESET	=	"\x1b[0m"
GREY	=	"\x1b[30m"
RED		=	"\x1b[31m"
GREEN	=	"\x1b[32m"
YELLOW	=	"\x1b[33m"
BLUE	=	"\x1b[34m"
PURPLE	=	"\x1b[35m"
CYAN	=	"\x1b[36m"
WHITE	=	"\x1b[37m"

.PHONY	: all clean fclean re bonus
