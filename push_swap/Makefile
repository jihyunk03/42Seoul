NAME	= push_swap
BONUS	= checker

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
AR		= ar -rcs

SRCS	= push_swap.c \
		  free_all.c \
		  stack_init.c \
		  stack_init_utils.c \
		  short_sort.c \
		  op_swap.c \
		  op_push.c \
		  op_rotate.c \
		  op_rv_rotate.c \
		  check_stack.c \
		  a_sort_to_b.c \
		  b_sort_to_a.c
OBJS	= $(SRCS:.c=.o)
INCD	= push_swap.h \
		  struct_info.h \
		  define_enum.h

B_SRCS	= checker.c \
		  free_all.c \
		  stack_init.c \
		  stack_init_utils.c \
		  op_swap.c \
		  op_push.c \
		  op_rotate.c \
		  op_rv_rotate.c \
		  check_stack.c
B_OBJS	= $(B_SRCS:.c=.o)
B_INCD	= checker.h \
		  struct_info.h \
		  define_enum.h

LIB		= my_libft/lib_jihykim2.a

all		: $(LIB) $(NAME)

$(LIB)	:
	@$(MAKE) -C $(dir $(LIB))

$(NAME)	: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo $(GREEN) "⚡︎ [ push_swap ]	Ready to use push_swap" $(RESET)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@$(MAKE) -C $(dir $(LIB)) clean
	@echo $(YELLOW) "✭  [ my_libft ]	Removed Object files" $(RESET)
	@$(RM) $(OBJS) $(B_OBJS)
	@echo $(GREEN) "⚡︎ [ push_swap ]	Removed Object files" $(RESET)

fclean	: clean
	@$(MAKE) -C $(dir $(LIB)) fclean
	@echo $(YELLOW) "✭  [ my_libft ]	Removed lib_jihykim2.a" $(RESET)
	@$(RM) $(NAME) $(BONUS)
	@echo $(GREEN) "⚡︎ [ push_swap ]	Removed push_swap" $(RESET)
	@echo $(GREEN) "⚡︎ [ checker ]		Removed checker" $(RESET)

re		:
	@$(MAKE) fclean
	@$(MAKE) all

bonus	: $(BONUS)

$(BONUS): $(B_OBJS)
	@$(CC) $(CFLAGS) $(B_OBJS) $(LIB) -o $(BONUS)
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
