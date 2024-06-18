/*
** EPITECH PROJECT, 2017
** my_print_colors.c
** File description:
**
*/

#include "ls.h"

void write_blue(const char *str)
{
	const char *BLUE = "\x1B[94m";
	const char *RESET = "\033[0m";

	if (contain_letter('f')) {
		my_put_str(str);
		return;
	}
	my_put_str(BLUE);
	my_put_str(str);
	my_put_str(RESET);
}

void write_yellow(const char *str)
{
	const char *BRED = "\x1B[41m";
	const char *YEL = "\x1B[93m";
	const char *RESET = "\033[0m";
	const char *RESETB = "\x1B[49m";

	if (contain_letter('f')) {
		my_put_str(str);
		return;
	}
	my_put_str(BRED);
	my_put_str(YEL);
	my_put_str(str);
	my_put_str(RESET);
	my_put_str(RESETB);
}

void write_cyan(const char *str)
{
	const char *CYAN = "\x1B[36m";
	const char *RESET = "\033[0m";

	if (contain_letter('f')) {
		my_put_str(str);
		return;
	}
	my_put_str(CYAN);
	my_put_str(str);
	my_put_str(RESET);
}

void write_green(const char *str)
{
	const char *BOLD = "\x1B[1m";
	const char *GREEN = "\x1B[32m";
	const char *RESET = "\033[0m";
	const char *RESETB = "\x1B[49m";

	if (contain_letter('f')) {
		my_put_str(str);
		return;
	}
	my_put_str(BOLD);
	my_put_str(GREEN);
	my_put_str(str);
	my_put_str(RESET);
	my_put_str(RESETB);
}