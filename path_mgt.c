#include "shell_header.h"

/**
 * path_concat - Search for and execute a command in dir. specified in PATH
 *
 * @arg_array: function argument
 * @absolute_path: function argument
 * @name: function arguemnt
 *
 * Return: void
 */
void path_concat(char **arg_array, char *absolute_path, char *name)
{
	ssize_t j;
	int ret, absolute_path_length;
	char *path_value = get_path_value(), *absolute_path_ptr = absolute_path, *dir;

	if (arg_array[0][0] == '/')
	{
		/* Command has an absolute path, skip path concatenation */
		for (j = 0 ; arg_array[0][j] != '\0' ; j++)
			absolute_path[j] = arg_array[0][j];
		absolute_path[j] = '\0';
		ret = execve(absolute_path, arg_array, environ);
		if (ret == -1)
			handle_exit_failure(arg_array, name);
	}
	else if (path_value != NULL)
	{
		dir = custom_str_tokenise(path_value, ":");
		while (dir != NULL)
		{
			absolute_path_length = custom_string_length(dir) + 1 + custom_string_length(arg_array[0]) + 1;
			if (absolute_path_length <= (int)sizeof(absolute_path))
			{
				custom_string_copy(absolute_path_ptr, dir);
				absolute_path_ptr += custom_string_length(dir);
				*absolute_path_ptr++ = '/';
				custom_string_copy(absolute_path_ptr, arg_array[0]);
			}
			if (access(absolute_path, X_OK) == 0)
			{
				ret = execve(absolute_path, arg_array, environ);
				if (ret == -1)
					handle_exit_failure(arg_array, name);
				break;
			}
			else
				dir = custom_str_tokenise(NULL, ":");
		}
	}
	handle_exit_failure(arg_array, name);
}

/**
 * get_path_value - retrieves the value of the "PATH" environment variable
 *
 * Return: path value
 */
char *get_path_value(void)
{
	char **env = environ;
	static char *path_value;
	char *path;

	while (*env != NULL)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			path_value = custom_str_duplicate(*env + 5);
			break;
		}
		env++;
	}

	if (path_value != NULL && *path_value == '\0')
		return (NULL);

	path = path_value;
	while (*path_value != '\0')
	{
		if (*path_value == ':')
		{
			*path_value = '\0';
			path_value++;
			break;
		}
		path_value++;
	}

	return (path);
}
