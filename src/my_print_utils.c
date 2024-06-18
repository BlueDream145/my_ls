/*
** EPITECH PROJECT, 2017
** my_print_utils.c
** File description:
**
*/

#include "ls.h"

void print_size_space(struct content file, int max_digits)
{
	int i;

	if (contain_letter('k') == 1)
		for (i = 0; i + number_digits(file.size / 8) < max_digits; i++)
			my_put_char(' ');
	else
		for (i = 0; i + number_digits(file.size) < max_digits; i++)
			my_put_char(' ');
}

int file_end_with(char *filename, char c)
{
	int i;

	for (i = 0; filename[i]; i++)
		if (filename[i + 1] == '\0' && filename[i] == c)
			return (1);
	return (0);
}

int dir_exist(char *file_path)
{
	DIR *dir = opendir(file_path);

	if (dir == NULL)
		return (0);
	else {
		closedir(dir);
		return (1);
	}
}

int ignored_file(struct content entry)
{
	if ((!contain_letter('a') && !contain_letter('f') && entry.hidden == 1)
	|| (contain_letter('B') && file_end_with(entry.file_name, '~') == 1))
		return (1);
	return (0);
}

int basic_display(void)
{
	if (contain_letter('f'))
		return (1);
	if (!contain_letter('l') && !contain_letter('g') &&
		!contain_letter('n') && !contain_letter('o'))
		return (1);
	else
		return (0);
}