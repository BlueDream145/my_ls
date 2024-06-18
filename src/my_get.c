/*
** EPITECH PROJECT, 2017
** my_get.c
** File description:
**
*/

#include "ls.h"

char *get_filename_from_path(char *path)
{
	const char *ERROR_MALLOC = "Fatal error: malloc failed.\n";
	char *file_name;
	int path_len = my_strlen(path);
	int last_slash = 0;
	int i = 0;

	for (i = 0; path[i]; i++)
		if (path[i] == '/')
			last_slash = i + 1;
	if (i == 0)
		return (path);
	file_name = malloc(sizeof(char) * (path_len - last_slash));
	if (file_name == NULL)
		report_error(ERROR_MALLOC);
	for (i = last_slash; path[i]; i++)
		file_name[i - last_slash] = path[i];
	return (file_name);
}

struct content get_file_content(struct stat st, char *name, char type,
int status)
{
	struct content dir_content;

	if (name[0] == '.')
		dir_content.hidden = 1;
	dir_content.stat = st;
	dir_content.file_name = name;
	dir_content.file_type = type;
	dir_content.mode = st.st_mode;
	dir_content.status = status;
	dir_content.size = st.st_size;
	return (dir_content);
}