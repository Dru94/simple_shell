#include "shell_header.h"

/**
 * process_id - Creates a child process to execute a command and wait for its
 * completion
 *
 * @argc: function argument
 * @command: function argument
 * @name: function argument
 *
 * Return: void
 */
void process_id(int argc, char *command, char *name)
{
	pid_t pid, parent_pid = getpid();

	pid = fork();
	if (pid < 0)
	{
		perror(name);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		child_pid(argc, command, parent_pid, name);
	else
		wait(NULL); /* Parent process */
}

/**
 * child_pid - Execute the command in the child process
 *
 * @argc: function argument
 * @command: function argument
 * @parent_pid: function argument
 * @name: function argument
 *
 * Return: void
 */
void child_pid(int argc, char *command, pid_t parent_pid, char *name)
{
	char *token, abs_path[1024], *path_value;
	int arg_count = 0, command_executed = 0, i;
	char **arg_array = malloc((argc + 1) * sizeof(char *));

	if (arg_array == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	token = custom_str_tokenise(command, " ");
	while (token != NULL)
	{
		arg_array[arg_count++] = custom_str_duplicate(token);
		token = custom_str_tokenise(NULL, " ");
	}
	arg_array[arg_count] = NULL;
	exit_call(arg_array, parent_pid);
	print_env(arg_array);
	set_environment(arg_array);
	unset_environment(arg_array);
	path_value = get_path_value();
	while (path_value != NULL && !command_executed)
	{
		path_concat(arg_array, abs_path, name);
		if (access(abs_path, X_OK) == 0)
		{
			command_executed = 1;
			break;
		}
		path_value = custom_str_tokenise(NULL, ":");
	}
	if (!command_executed)
		handle_exit_success(arg_array, name);
	for (i = 0 ; i < argc ; i++)
		free(arg_array[i]);
	free(arg_array);
	exit(EXIT_SUCCESS);
}

/**
 * exit_call - handles if the command is exit
 *
 * @arg_array: function argument
 * @parent_pid: function argument
 *
 * Return: void
 */
void exit_call(char **arg_array, pid_t parent_pid)
{
	if (custom_string_compare(arg_array[0], "exit") == 0)
	{
		kill(parent_pid, SIGUSR1); /* Notify the parent process to exit */
		free(arg_array);
		exit(EXIT_SUCCESS);
	}
}

