#include "shell_header.h"

/**
 * custom_string_compare - Compares two string
 *
 * @string1: function argument
 * @string2: function argument
 *
 * Return: integer less than, equal to, or greater than 0 if `string1`
 * is found, respectively, to be less than, to match, or to be greater
 * than `string2`.
 */
int custom_string_compare(const char *string1, const char *string2)
{
	if (string1 == NULL && string2 == NULL)
		return (0);

	if (string1 == NULL)
		return (-1);

	if (string2 == NULL)
		return (1);

	while (*string1 && (*string1 == *string2))
	{
		string1++;
		string2++;
	}
	return ((unsigned char)(*string1) - (unsigned char)(*string2));
}
