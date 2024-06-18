/*
** EPITECH PROJECT, 2017
** my_print_fields.c
** File description:
**
*/

#include "ls.h"

void print_acl(struct content file)
{
	if (S_ISDIR(file.mode))
		my_put_char('d');
	else if (DT_LNK == file.file_type) {
		my_put_str("lrwxrwxrwx. ");
		my_put_nbr(file.stat.st_nlink);
		my_put_char(' ');
		return;
	}
	else
		my_put_char('-');
	my_put_str((file.mode & S_IRUSR) ? "r" : "-");
	my_put_str((file.mode & S_IWUSR) ? "w" : "-");
	my_put_str((file.mode & S_IXUSR) ? "x" : "-");
	my_put_str((file.mode & S_IRGRP) ? "r" : "-");
	my_put_str((file.mode & S_IWGRP) ? "w" : "-");
	my_put_str((file.mode & S_IXGRP) ? "x" : "-");
	my_put_str((file.mode & S_IROTH) ? "r" : "-");
	my_put_str((file.mode & S_IWOTH) ? "w" : "-");
	my_put_str((file.mode & S_IXOTH) ? "x" : "-");
	my_put_str(". ");
	my_put_nbr(file.stat.st_nlink);
}

void print_user_info(struct content file)
{
	struct passwd *pw = getpwuid(file.stat.st_uid);
	struct group  *gr = getgrgid(file.stat.st_gid);

	if (contain_letter('n')) {
		my_put_nbr(file.stat.st_uid);
		my_put_char(' ');
		my_put_nbr(file.stat.st_uid);
		return;
	}
	if (!contain_letter('g')) {
		if (pw != 0)
			my_put_str(pw->pw_name);
		else
			my_put_str("Unknown");
		my_put_char(' ');
	}
	if (!contain_letter('o') && gr != 0)
		my_put_str(gr->gr_name);
	else if (!contain_letter('o'))
		my_put_str("Unknown");
}

void print_date(struct content file)
{
	char *date = malloc(sizeof(char) * 36);
	int i;

	if (date == NULL)
		report_error("Fatal error: malloc failed.");
	my_put_char(' ');
	if (contain_letter('u'))
		date = ctime(&file.stat.st_atime);
	else
		date = ctime(&file.stat.st_mtime);
	for (i = 0; i < 4; i++)
		delete_char(date, 0);
	for (i = 11; i < 19; i++)
		delete_char(date, 12);
	date[my_strlen(date) - 1] = '\0';
	my_put_str(date);
}

void print_size(struct content file)
{
	int max_digits = -1;
	struct content entry;
	int i;

	for (i = 0; i < search_entry.files_len; i++) {
		entry = search_entry.files[i];
		if (number_digits(entry.size) > max_digits &&
		contain_letter('k') == 1)
			max_digits = number_digits(entry.size / 8);
		else if (number_digits(entry.size) > max_digits)
			max_digits = number_digits(entry.size);
	}
	print_size_space(file, max_digits);
	my_put_char(' ');
	if (contain_letter('k') == 1)
		my_put_nbr(file.size / 8);
	else
		my_put_nbr(file.size);
}

void print_link_target(struct content file)
{
	const char *ERROR_MALLOC = "Fatal error: malloc failed.";
	size_t size = 256;
	ssize_t link_len;
	char *buffer = malloc(size);

	if (buffer == NULL)
		report_error(ERROR_MALLOC);
	link_len = readlink(file.file_name, buffer, size);
	if (link_len < 0)
		return;
	if ((size_t)link_len < size) {
		buffer[link_len] = '\0';
		my_put_str(" -> ");
		my_put_str(buffer);
	}
}