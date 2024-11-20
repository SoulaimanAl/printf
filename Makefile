SRC = ft_printf.c	handle.c	print_add.c	print_res.c	more_functions.c	print_hex.c	print_integer.c	print_string.c	print_unsigned.c	sources.c	sources1.c
OBJ = $(SRC:%.c=%.o)
SRC_BONUS = ft_printf_bonus.c	print_add_bonus.c	print_res_bonus.c	handle_bonus.c	print_hex_bonus.c	print_string_bonus.c	sources1_bonus.c	more_functions_bonus.c	print_integer_bonus.c 	print_unsigned_bonus.c	sources_bonus.c
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

%.o: %.c
	cc -I. $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
