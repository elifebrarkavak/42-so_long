CC = cc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lminilibx-linux -Lft_printf
LDLIBS = ft_printf/libftprintf.a -lmlx -lX11 -lXext
SRCS = check_map.c so_long_utils.c hook_functions.c main.c move.c obj_check.c \
       get_next_line/get_next_line.c get_next_line/get_next_line_utils.c error.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) ft_printf/libftprintf.a minilibx-linux/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

ft_printf/libftprintf.a:
	$(MAKE) -C ft_printf

minilibx-linux/libmlx.a:
	$(MAKE) -C minilibx-linux

clean:
	rm -f $(OBJS)
	rm -f get_next_line/get_next_line.o get_next_line/get_next_line_utils.o
	$(MAKE) -C ft_printf clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C minilibx-linux clean

re: fclean all
