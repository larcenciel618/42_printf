NAME		= libftprintf.a

SRCS		= ft_printf.c ft_putptr.c ft_putnbr.c ft_putstr.c \
			ft_putchar.c ft_puthex.c ft_putunbr.c

OBJS		= $(SRCS:%.c=%.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rc ${NAME} ${OBJS}

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

PHONY: fclean clean all re






