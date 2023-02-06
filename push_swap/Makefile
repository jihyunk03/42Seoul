NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  free_all.c \
		  stack_init.c \
		  operator_s.c operator_p.c operator_r.c operator_r_r.c
OBJS	= $(SRCS: .c=.o)

INCD	= push_swap.h \
		  ./libft/libft.h \
		  struct_info.h

all		: libft $(NAME)

make -C ~~
-lft # libft.a를 사용하기 위한 옵션() lib와 .a를 제외한 이름을 인식
