NAME = libftprintf.a

FILE_NAME = ft_printf.c ft_check_char.c ft_check_number.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(FILE_NAME:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
