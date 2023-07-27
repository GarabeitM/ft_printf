NAME	= libftprintf.a

SRCS	= ft_printf.c txt.c nbrs.c

OBJS	= $(SRCS:.c=.o)

CC	= cc

FLAGS	= -Wall -Wextra -Werror

HEADER = ft_printf.h

RM	= rm -f

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $(FLAGS) -o $@ $<

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re