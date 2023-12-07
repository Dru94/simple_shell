#include "shell_header.h"

/**
 * print_env - Prints the program's environmental variables
 *
 * @arg_array: function argument
 *
 * Return: void
 */
void print_env(char **arg_array)
{
	if (custom_string_compare(arg_array[0], "env") == 0)
	{
		print_environment(); /* Call the funciton to print the environment */
		free(arg_array);
		exit(EXIT_SUCCESS);
	}
}

/**
 * print_environment - Prints the current environment variables
 *
 * Return: void
 */
void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
