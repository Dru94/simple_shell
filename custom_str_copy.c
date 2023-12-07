#include "shell_header.h"

/**
 * custom_string_copy - Copies a string from source to destination
 *
 * @dest: function argument
 * @src: function argument
 *
 * Return: Pointer to the destination string `dest`
 */
void custom_string_copy(char *dest, const char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

