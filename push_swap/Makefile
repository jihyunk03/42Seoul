NAME	= push_swap
NAME2	= checker

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
AR		= ar -rcs

SRCS	= push_swap.c \
		  free_all.c \
		  stack_init.c stack_init_utils.c \
		  op_swap.c op_push.c op_rotate.c op_rv_rotate.c \
		  check_stack.c \
		  a_sort_to_b.c \
		  b_sort_to_a.c \
		  short_sort.c
OBJS	= $(SRCS:.c=.o)
INCD	= push_swap.h \
		  struct_info.h \
		  define_enum.h

SRCS2	= checker.c \
		  free_all.c \
		  stack_init.c stack_init_utils.c \
		  op_swap.c op_push.c op_rotate.c op_rv_rotate.c \
		  check_stack.c
OBJS2	= $(SRCS2:.c=.o)
INCD2	= checker.h \
		  struct_info.h \
		  define_enum.h

.PHONY	: all
all		: libs $(NAME)

libs	:
	@$(MAKE) -C my_libft/

$(NAME)	: $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L ./my_libft/ -l_jihykim2
	@echo "[push_swap] Ready"

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY	: clean
clean	:
	@$(MAKE) -C my_libft/ clean
	@$(RM) $(OBJS) $(OBJS2)
	@echo "[push_swap & checker] Removed Object files"

.PHONY	: fclean
fclean	: clean
	@$(RM) ./my_libft/lib_jihykim2.a $(NAME) $(NAME2)
	@echo "[my_libft] Removed lib_jihykim2.a"
	@echo "[push_swap & checker] Removed push_swap"

.PHONY	: re
re		:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY	: bonus
bonus	: $(NAME2)

$(NAME2): $(OBJS2)
	@$(CC) $(CFLAGS) -o $(NAME2) $(OBJS2) -L ./my_libft/ -l_jihykim2
	@echo "[checker] Ready"
