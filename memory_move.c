#include "shell_header.h"

/**
 * memory_move - Copies a block of memory to another location
 *
 * @dest: function argument
 * @src: function argument
 * @n: function argument
 *
 * Return: On success, the function returns a pointer to the
 * desination memory block `dest`
 */
void *memory_move(void *dest, const void *src, size_t n)
{
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;
	size_t i;

	if (n == 0 || d == s)
		return (dest);

	if (d < s)
	{
		for (i = 0; i < n; i++)
			d[i] = s[i];
	}
	else
	{
		for (i = n; i > 0; i--)
			d[i - 1] = s[i - 1];
	}

	return (dest);
}

