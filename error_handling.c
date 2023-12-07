#include "shell_header.h"

/**
 * handle_exit_success - Handles the occurence of an error
 *
 * @arg_array: function argument
 * @name: function argument
 *
 * Return: void
 */
void handle_exit_success(char **arg_array, char *name)
{
	perror(name);
	free(arg_array);
	exit(EXIT_SUCCESS);
}

/**
 * handle_exit_failure - Handles the occurence of an error
 *
 * @arg_array: function argument
 * @name: function argument
 *
 * Return:
 */
void handle_exit_failure(char **arg_array, char *name)
{
	perror(name);
	free(arg_array);
	exit(EXIT_FAILURE);
}

/**
 * handle_exit - function handles exit by changing close_shell flag to 1
 *
 * @signal: function argument
 *
 * Return: void
 */
void handle_exit(int signal)
{
	if (signal == SIGUSR1)
		exit(EXIT_SUCCESS);
}

