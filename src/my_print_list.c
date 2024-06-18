/*
** EPITECH PROJECT, 2017
** my_print_list.c
** File description:
**
*/

#include "ls.h"

int basic_print_elem(struct content entry, int wrote)
{
	if (ignored_file(entry) == 1)
		return (wrote);
	if (contain_letter('1') && wrote == 1)
		my_put_char('\n');
	else if (wrote == 1)
		my_put_str("  ");
	wrote = 1;
	print_file_name(entry);
	return (wrote);
}

int print_elem(struct content entry)
{
	if (ignored_file(entry) == 1)
		return (0);
	print_acl(entry);
	my_put_char(' ');
	print_user_info(entry);
	print_size(entry);
	print_date(entry);
	my_put_char(' ');
	print_file_name(entry);
	return (1);
}

int print_single_file(int display, int wrote)
{
	if (display == 1 && !basic_display())
		my_put_char('\n');
	if (basic_display())
		wrote = basic_print_elem(search_entry.single_files
		[search_entry.single_files_len - 1], wrote);
	else
		print_elem(search_entry.single_files[
			search_entry.single_files_len - 1]);
	return (wrote);
}

void print_header_files(int i)
{
	if (search_entry.path_len > 1 || contain_letter('R')) {
		if (contain_letter('R') && (search_entry.list_path[i][0] != '.'
		&& search_entry.list_path[i][0] != '\0'))
			my_put_str("./");
		my_put_str(search_entry.list_path[i]);
		my_put_char(':');
		my_put_char('\n');
	}
	search_entry.total_blocks = 0;
}

void manage_recursive(struct stat st, char *tmp, char *full_path,
struct content ct)
{
	if ((contain_letter('R') && S_ISDIR(st.st_mode))
	&& ((ct.hidden != 1) || (contain_letter('a') && ct.hidden == 1))) {
		if (!(st.st_mode & S_IRUSR)) {
			my_put_str("Cannot open, permission denied : ./");
			my_put_str(full_path);
			return;
		}
		my_strcat(tmp, full_path);
		search_entry.list_path[search_entry.path_len] = tmp;
		search_entry.path_len++;
	}
}