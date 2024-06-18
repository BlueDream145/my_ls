/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "ls.h"

int main(int ac, char **as)
{
	int i;

	parse_args(ac, as);
	print_single_files();
	for (i = 0; i < search_entry.path_len; i++) {
		if (!dir_exist(search_entry.list_path[i]))
			continue;
		print_header_files(i);
		prepare_list(i);
		my_amazing_sorter();
		if (basic_display())
			basic_print_list();
		else
			print_list();
		if (search_entry.path_len > 1 && i + 1 +
		search_entry.single_files_len < search_entry.path_len)
			my_put_char('\n');
	}
	return (0);
}

int prepare_single_file(char *file_path)
{
	const char *ERROR_STATUS = "No such file or directory.\n";
	struct stat info;
	int status = stat(file_path,&info);

	if (status != 0)
		report_error(ERROR_STATUS);
	if (search_entry.single_files_len == 0)
		search_entry.single_files = malloc(sizeof(struct content)
		* 999);
	search_entry.single_files[search_entry.single_files_len] =
	get_file_content(info, file_path, 'f', status);
	search_entry.single_files_len++;
	return (1);
}

void prepare_list(int index)
{
	DIR *rep = opendir(search_entry.list_path[index]);
	struct dirent *reader;
	struct content *dir_content;
	char *full_path = NULL;
	int i = 0;

	dir_content = malloc(sizeof(struct content) * 999);
	if (rep == NULL)
		return;
	while ((reader = readdir(rep))) {
		full_path = prepare_path(reader, index);
		prepare_file(full_path, dir_content, reader, i);
		i++;
		search_entry.files_len = i;
		free(full_path);
	}
	closedir(rep);
	search_entry.files = dir_content;
}

void prepare_file(char *full_path, struct content *dir_content,
struct dirent *reader, int i)
{
	int status;
	struct stat st;
	char *tmp = malloc(sizeof(char) * (my_strlen(full_path)) + 1);

	my_printf("", full_path);
	status = stat(full_path, &st);
	dir_content[i] = get_file_content(st, reader->d_name,
	reader->d_type, status);
	if (dir_content[i].hidden != 1 ||
	(contain_letter('a') && dir_content[i].hidden == 1))
		search_entry.total_blocks +=
		(int)dir_content[i].stat.st_blocks;
	manage_recursive(st, tmp, full_path, dir_content[i]);
}

char *prepare_path(struct dirent *reader, int index)
{
	char *full_path = NULL;
	int len = (my_strlen(search_entry.list_path[index]) +
	my_strlen(reader->d_name) + 2);

	if (search_entry.list_path[index][0] != '.') {
		full_path = malloc(sizeof(char) * len);
		my_strcpy(full_path, search_entry.list_path[index]);
		my_strcat(full_path, "/");
		my_strcat(full_path, reader->d_name);
	}
	else {
		full_path = malloc(sizeof(char) * my_strlen(reader->d_name));
		my_strcpy(full_path, reader->d_name);
	}
	if (full_path == NULL)
		report_error("Fatal error: malloc failed.");
	return (full_path);
}