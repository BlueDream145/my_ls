##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	src/my_printf/my_convert.c \
		src/my_printf/my_param.c \
		src/my_printf/my_printf.c \
		src/my_printf/my_printf_basics.c \
		src/my_printf/my_printf_decimal.c \
		src/my_printf/my_printf_extra.c \
		src/my_printf/my_put_base.c \
		src/my_printf/my_put.c \
		src/my_printf/my_stdarg.c \
		src/my_printf/my_utils.c \
		src/my_printf/my_get.c \
		src/my_get.c \
		src/my_parser.c \
		src/my_print_colors.c \
		src/my_print_fields.c \
		src/my_print_list.c \
		src/my_print_utils.c \
		src/my_print.c \
		src/my_report.c \
		src/my_sorter.c \
		src/my_string.c \
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

all:	$(NAME)

$(NAME):
	gcc $(SRC) -Wall -Wextra -I include -o $(NAME) -g

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
