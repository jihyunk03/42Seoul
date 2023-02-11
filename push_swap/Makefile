NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
AR		= ar -rcs

SRCS	= push_swap.c \
		  free_all.c \
		  stack_init.c stack_init_utils.c \
		  operator_s.c operator_p.c operator_r.c operator_r_r.c \
		  check_stack.c \
		  a_sort_to_b.c \
		  b_sort_to_a.c \
		  short_sort.c
OBJS	= $(SRCS:.c=.o)
INCD	= push_swap.h \
		  struct_info.h \
		  number_define.h

.PHONY	: all
all		: libs $(NAME)

libs	:
	$(MAKE) -C my_libft/

$(NAME)	: $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L ./my_libft/ -l_jihykim2
	@echo "[push_swap] Ready"

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY	: clean
clean	:
	$(MAKE) -C my_libft/ clean
	@$(RM) $(OBJS)
	@echo "[push_swap] Removed Object files"

.PHONY	: fclean
fclean	:
	$(MAKE) clean
	$(MAKE) -C my_libft/ fclean
	@$(RM) $(NAME)
	@echo "[push_swap] Removed push_swap"

.PHONY	: re
re		:
	$(MAKE) fclean
	$(MAKE) all
