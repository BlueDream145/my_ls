/*
** EPITECH PROJECT, 2017
** ls.h
** File description:
**
*/

#ifndef ls_
#define ls_

#include <unistd.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include "print.h"

struct entry {
	char **list_path;
	struct content *files;
	struct content *single_files;
	int path_len;
	int files_len;
	int single_files_len;
	char *letters;
	int total_blocks;
} search_entry;

struct content {
	char *file_name;
	char file_type;
	struct stat stat;
	int status;
	int size;
	int mode;
	int hidden;
};

// main.c
int prepare_single_file(char *file_path);
void prepare_file(char *full_path, struct content *dir_content,
struct dirent *reader, int i);
void prepare_list(int index);
char *prepare_path(struct dirent *reader, int index);

// my_get.c
char *get_filename_from_path(char *path);
struct content get_file_content(struct stat st, char *name, char type,
int status);

// my_parser.c
int check_arg_syntax(char c);
void parse_args(int ac, char **as);
int process_arg(char *arg, int letters_index);
void process_path(char **as, int i);
int contain_letter(char c);

// my_print_colors.c
void write_blue(const char *str);
void write_yellow(const char *str);
void write_cyan(const char *str);
void write_green(const char *str);

// my_print_fields.c
void print_user_info(struct content file);
void print_acl(struct content file);
void print_date(struct content file);
void print_size(struct content file);
void print_link_target(struct content file);

// my_print_list.c
int basic_print_elem(struct content entry, int wrote);
int print_elem(struct content entry);
int print_single_file(int display, int wrote);
void print_header_files(int i);
void manage_recursive(struct stat st, char *tmp, char *full_path,
struct content ct);

// my_print_utils.c
void print_size_space(struct content file, int max_digits);
int file_end_with(char *filename, char c);
int dir_exist(char *file_path);
int ignored_file(struct content entry);
int basic_display(void);

// my_print.c
void basic_print_list(void);
void print_list(void);
void print_single_files(void);
void print_file_name(struct content entry);
void print_file_type(struct content file);

// my_report.c
void report_error(const char *str);

// my_sorter.c
void my_amazing_sorter(void);
int my_sort_alpha(int size, int success);
int my_sort_time(int size, int success);
void my_sort_reverse(int size);

// my_string.c
int my_strlen(char const *str);
char my_lower(char const c);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, const char *src);
char *my_strcpy(char *dest, char const *src);

#endif /* ls_ */