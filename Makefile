FLAGS = -Wall -Wextra -Werror
CC = cc
NAME = libftprintf.a
HEADER = ft_printf.h

LISTC = ft_printf.c \
		ft_printf_utils.c \
		ft_printf_do.c \

LISTO = $(LISTC:.c=.o)

%.o : %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(LISTO) $(HEADER) Makefile
	ar -rsc $@ $^

clean :
	rm -f $(LISTO)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
