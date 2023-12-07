#include "shell_header.h"

/**
 * custom_string_length - Calculates the length of the string
 *
 * @s: Pointer to the null terminated string
 *
 * Return: The length of the string
 */
int custom_string_length(const char *s)
{
	int count = 0;

	if (s == NULL)
		return (0);

	while (s[count] != '\0')
		count++;

	return (count);
}
