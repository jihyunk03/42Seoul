CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address
SRCS	= srcs/find_square.c srcs/functions.c srcs/functions2.c srcs/main.c srcs/map.c srcs/parse.c
OBJS	= ${SRCS:.c=.o}
INCD	= includes
NAME	= bsq


all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o $@

%.o: %.c
			${CC} ${CFLAGS} -c $< -o $@ -I ${INCD}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all
