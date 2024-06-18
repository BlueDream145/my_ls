/*
** EPITECH PROJECT, 2017
** bubble_sort_array.c
** File description:
**
*/

#include "ls.h"

void my_amazing_sorter(void)
{
	int size = search_entry.files_len;
	int success = 0;

	if (contain_letter('f') || contain_letter('U'))
		return;
	while (success == 0) {
		success = 1;
		if (contain_letter('t'))
			success = my_sort_time(size, success);
		else
			success = my_sort_alpha(size, success);
		size--;
	}
	if (contain_letter('r'))
		my_sort_reverse(size);
}

int my_sort_alpha(int size, int success)
{
	char *file1;
	char *file2;
	struct content tmp;
	int i = 0;

	for (i = 0; i < size - 1; i++) {
		file1 = search_entry.files[i].file_name;
		file2 = search_entry.files[i + 1].file_name;
		if (my_strcmp(file1, file2) > 0) {
			tmp = search_entry.files[i];
			search_entry.files[i] = search_entry.files[i + 1];
			search_entry.files[i + 1] = tmp;
			success = 0;
		}
	}
	return (success);
}

int my_sort_time(int size, int success)
{
	struct content file1;
	struct content file2;
	struct content tmp;
	int i = 0;

	for (i = 0; i < size - 1; i++) {
		file1 = search_entry.files[i];
		file2 = search_entry.files[i + 1];
		if (file1.stat.st_mtime < file2.stat.st_mtime) {
			tmp = search_entry.files[i];
			search_entry.files[i] = search_entry.files[i + 1];
			search_entry.files[i + 1] = tmp;
			success = 0;
		}
	}
	return (success);
}

void my_sort_reverse(int size)
{
	struct content tmp;
	int len = search_entry.files_len - 1;
	int i = 0;

	if (size == 0)
		size += 1;
	for (i = 0; i < len; i++) {
		tmp = search_entry.files[i];
		search_entry.files[i] = search_entry.files[len];
		search_entry.files[len] = tmp;
		len--;
	}
}