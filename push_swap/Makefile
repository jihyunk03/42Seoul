NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
AR		= ar -rcs

SRCS	= push_swap.c \
		  free_all.c \
		  stack_init.c stack_init_utils.c \
		  operator_s.c operator_p.c operator_r.c operator_r_r.c \
		  check_sort.c \
		  a_sort_to_b.c \
		  b_sort_to_a.c
OBJS	= $(SRCS:.c=.o)
INCD	= push_swap.h \
		  struct_info.h

.PHONY	: all
all		: $(NAME)

$(NAME)	: $(OBJS)
	$(MAKE) -C libft/ re

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY	: clean
clean	:
	$(MAKE) -C libft/ clean

.PHONY	: fclean
fclean	: clean
	$()



make -C ~~
-lft # libft.a를 사용하기 위한 옵션() lib와 .a를 제외한 이름을 인식
