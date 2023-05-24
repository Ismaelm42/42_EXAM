NAME = libftprintf.a

SRC =	ft_printf.c		\
		ft_printf2.c	\

OBJT = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

all: $(NAME)

$(NAME): $(OBJT)
	gcc $(CFLAGS) -c $(SRC)
	$(AR) $(NAME) $(OBJT)

clean:
	$(RM) $(OBJT)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
