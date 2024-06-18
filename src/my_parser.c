/*
** EPITECH PROJECT, 2017
** my_parser.c
** File description:
**
*/

#include "ls.h"

void parse_args(int ac, char **as)
{
	const int allowed_syntax_len = 20;
	const char *ERROR_MALLOC = "Fatal error: malloc failed";
	int letters_index = 0;
	int i = 1;

	search_entry.path_len = 0;
	search_entry.letters = malloc(sizeof(char) * allowed_syntax_len);
	search_entry.list_path = malloc(sizeof(char*) * ac);
	if (search_entry.letters == NULL || search_entry.list_path == NULL)
		report_error(ERROR_MALLOC);
	for (i = 1; i < ac; i++)
		if (as[i][0] == '-')
			letters_index = process_arg(as[i], letters_index);
		else
			process_path(as, i);
	if (search_entry.path_len == 0) {
		search_entry.list_path[0] = ".";
		search_entry.path_len++;
	}
}

int process_arg(char *arg, int letters_index)
{
	int i;

	for (i = 1; arg[i]; i++)
		if (check_arg_syntax(arg[i]) == 1) {
			search_entry.letters[letters_index] = arg[i];
			letters_index++;
		}
	return (letters_index);
}

void process_path(char **as, int i)
{
	int len = 0;

	len = my_strlen(as[i]);
	if (as[i][len - 1] == '/' && len > 1)
		as[i][len - 1] = '\0';
	search_entry.list_path[search_entry.path_len] = as[i];
	search_entry.path_len++;
}

int check_arg_syntax(char c)
{
	const char *allowed_syntax = "lRdrtuFgfaAkBfgnopU1";
	int i;

	for (i = 0; allowed_syntax[i]; i++)
		if (allowed_syntax[i] == c)
			return (1);
	return (0);
}

int contain_letter(char c)
{
	int i;

	for (i = 0; search_entry.letters[i]; i++)
		if (search_entry.letters[i] == c)
			return (1);
	return (0);
}