CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)
RM = rm -f
AR = ar -rcs
INCD = ft_printf.h
NAME = libftprintf.a

all: $(OBJS)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCD)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all fclean clean re bonus
