SRC = ft_printf.c handle.c print_add.c   print_res.c more_functions.c print_hex.c     print_integer.c print_string.c  print_unsigned.c sources.c        sources2.c       sources3.c
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	cc -I. $(CFLAGS) -c $<
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
