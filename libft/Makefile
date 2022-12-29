CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c \
	   ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	   ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	   ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	   ft_calloc.c ft_strdup.c ft_strmapi.c ft_striteri.c\
	   ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS = $(SRCS:.c=.o)
B_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
B_OBJS = $(B_SRCS:.c=.o)
INCD = libft.h
NAME = libft.a

ifdef BONUS
	OBJS_ALL = $(B_OBJS) $(OBJS)
else
	OBJS_ALL = $(OBJS)
endif

all: $(NAME)
	sleep 1

bonus:
	$(MAKE) BONUS=1 $(NAME)

$(NAME): $(OBJS_ALL)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCD)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all fclean clean re bonus
