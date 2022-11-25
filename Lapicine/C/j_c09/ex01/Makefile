CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c 
OBJS	= ${SRCS:.c=.o}
INCD	= includes
NAME	= libft.a

all:		${NAME}

${NAME}:${OBJS}
	ar rcs $@ $^

%.o: %.c
			${CC} ${CFLAGS} -c $< -o $@ -I ${INCD}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all
