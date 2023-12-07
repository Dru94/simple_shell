#include "shell_header.h"

/**
 * custom_str_duplicate - duplicates a string
 *
 * @str: function argument string to be duplicated
 *
 * Return: duplicated string
 */
char *custom_str_duplicate(const char *str)
{
	size_t len = custom_string_length(str);
	char *dup = malloc(len + 1);

	if (dup != NULL)
	{
		custom_string_copy(dup, str);
		return (dup);
	}
	return (NULL);
}

