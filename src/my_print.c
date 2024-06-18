/*
** EPITECH PROJECT, 2017
** my_print.c
** File description:
**
*/

#include "ls.h"

void basic_print_list(void)
{
	int i;
	int wrote = 0;

	for (i = 0; i < search_entry.files_len; i++)
		wrote = basic_print_elem(search_entry.files[i], wrote);
	my_put_char('\n');
}

void print_list(void)
{
	int i;

	my_put_str("total ");
	my_put_nbr(search_entry.total_blocks / 2);
	my_put_char('\n');
	for (i = 0; i < search_entry.files_len; i++)
		if (print_elem(search_entry.files[i]))
			my_put_char('\n');
}

void print_single_files(void)
{
	int i;
	int wrote;
	int display = 0;

	for (i = 0; i < search_entry.path_len; i++) {
		if (dir_exist(search_entry.list_path[i]))
			continue;
		prepare_single_file(search_entry.list_path[i]);
		if (!(search_entry.single_files
		[search_entry.single_files_len - 1].stat.st_mode & S_IRUSR)) {
			my_put_str("Cannot open: Permission denied\n");
			continue;
		}
		wrote = print_single_file(display, wrote);
		display = 1;
	}
	if (search_entry.single_files_len == 0)
		return;
	my_put_char('\n');
	if (search_entry.path_len - search_entry.single_files_len > 0)
		my_put_char('\n');
}

void print_file_name(struct content file)
{
	if (S_ISDIR(file.mode)) {
		write_blue(file.file_name);
		if (contain_letter('p'))
			my_put_char('/');
		return;
	}
	if (DT_LNK == file.file_type)
		write_cyan(file.file_name);
	else if ((S_ISREG(file.mode)) && (file.mode & 0111))
		write_green(file.file_name);
	else
		my_put_str(file.file_name);
	if (DT_LNK == file.file_type && contain_letter('l'))
		print_link_target(file);
	print_file_type(file);
}

void print_file_type(struct content file)
{
	if (!contain_letter('F'))
		return;
	if (S_ISDIR(file.mode))
		my_put_char('/');
	if (S_ISFIFO(file.mode))
		my_put_char('|');
	else if ((S_ISREG(file.mode)) && (file.mode & 0111))
		my_put_char('*');
}