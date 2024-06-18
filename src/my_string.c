/*
** EPITECH PROJECT, 2017
** my_string.c
** File description:
**
*/

#include "ls.h"

int my_strlen(char const *str)
{
	int i = 0;

	for (i = 0; str[i]; i++);
	return (i);
}

char my_lower(char const c)
{
	char value;

	if(c >= 'A' && c <= 'Z')
		value = c + 32;
	else
		value = c;
	return (value);
}

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	while ((my_lower(s1[i]) == my_lower(s2[i])) &&
	(s1[i] != '\0') && (s2[i] != '\0')) {
		i++;
	}
	return (my_lower(s1[i]) - my_lower(s2[i]));
}

char *my_strcat(char *dest, const char *src) // s, append
{
	char *result = dest;

	while (*dest) {
		dest++;
	}
	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
	return (result);
}

char *my_strcpy(char *dest, const char *src)
{
	char *result = dest;

	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
	return (result);
}