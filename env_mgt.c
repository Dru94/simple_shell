#include "shell_header.h"

/**
 * set_environment - Set an environment variable
 *
 * @arg_array: function argument
 *
 * Return: void
 */
int set_environment(char **arg_array)
{
	if (strcmp(arg_array[0], "setenv") == 0)
	{
		if (arg_array[1] != NULL && arg_array[2] != NULL)
		{
			if (custom_set_environment(arg_array[1], arg_array[2]) == -1)
			{
				free(arg_array);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			fprintf(stderr, "setenv: Invalid arguments\n");
			free(arg_array);
			exit(EXIT_FAILURE);
		}
		free(arg_array);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

/**
 * unset_environment - Unset an environment variable
 *
 * @arg_array: function argument
 *
 * Return: void
 */
int unset_environment(char **arg_array)
{
	if (custom_string_compare(arg_array[0], "unsetenv") == 0)
	{
		if (arg_array[1] != NULL)
		{
			if (unset_environment(arg_array) == -1)
			{
				free(arg_array);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			fprintf(stderr, "unsetenv: Invalid argument\n");
			free(arg_array);
			exit(EXIT_FAILURE);
		}
		free(arg_array);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

/**
 * custom_set_environment -
 * Function sets a custom environment variable with the
 * specified name and value
 *
 * @name: function argument
 * @value: function argument
 *
 * Return: On success, the function returns 0
 */
int custom_set_environment(const char *name, const char *value)
{
	char *args[3];

	args[0] = (char *)name;
	args[1] = (char *)value;
	args[2] = NULL;

	if (name == NULL || value == NULL)
	{
		fprintf(stderr, "setenv: Invalid arguments\n");
		return (-1);
	}

	if (set_environment(args) != 0)
	{
		fprintf(stderr, "setenv: Failed to set environment variable\n");
		return (-1);
	}

	return (0);
}

/**
 * custom_unset_enviroment -
 * Function unsets a custom specified environment variable
 *
 * @name: function argument
 *
 * Return: On success, the function returns 0
 */

int custom_unset_enviroment(const char *name)
{
	char *args[3];

	args[0] = (char *)name;

	args[1] = NULL;
	args[2] = NULL;

	if (args[0] == NULL)
	{
		fprintf(stderr, "unsetenv: Invalid argument\n");
		return (-1);
	}

	if (unset_environment(args) != 0)
	{
		fprintf(stderr, "unsetenv: Failed to unset environment variable\n");
		return (-1);
	}

	return (0);
}

