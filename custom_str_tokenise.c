#include "shell_header.h"

/**
 * custom_chr_search - Locates the first occurence of a character in the string
 *
 * @string: function argument
 * @c: function argument
 *
 * Return: On success, the funciton returns a pointer to the first occurence
 * of 'c' in the string `string`
 * If the character is not foud the function returns NULL
 */
char *custom_chr_search(const char *string, int c)
{
	while (*string != '\0')
	{
		if (*string == c)
			return ((char *)string);
		string++;
	}
	return (NULL);
}

/**
 * custom_str_tokenise - Tokenizes a string based on delimiters
 *
 * @str: function argument
 * @delimiter: function argument
 *
 * Return: On success, the function returns a pointer to the next token
 * If there are no more pointers the function returns NULL.
 */
char *custom_str_tokenise(char *str, const char *delimiter)
{
	static char *next_token;  /*stores the position of the next token*/
	char *token;

	if (str != NULL)
		next_token = str;
	else if (next_token == NULL)
		return (NULL);

	/*Find the start of the token*/
	while (*next_token != '\0' &&
			custom_chr_search(delimiter, *next_token) != NULL)
		next_token++;

	if (*next_token == '\0')
		return (NULL);

	token = next_token;  /*store the start of the token*/

	/*Find the end of the token*/
	while (*next_token != '\0' &&
			custom_chr_search(delimiter, *next_token) == NULL)
		next_token++;

	if (*next_token != '\0')
	{
		*next_token = '\0';
		next_token++;
	}
	/*null-terminate the token and move to the next position*/

	return (token);
}
