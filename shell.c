#include "shell_header.h"

/**
 * main - main function
 *
 * @argc: function argument > count
 * @argv: function argument > vector
 *
 * Return: On success, the function returns 0
 */
int main(int argc, char *argv[])
{
	char *command, *name = argv[0];
	int i, terminal = isatty(STDIN_FILENO), m = 0, n = 0;
	size_t bufsize = BUFFER_SIZE, read_line;

	command = (char *)malloc(bufsize * sizeof(char));
	signal(SIGUSR1, handle_exit);
	if (command == NULL)
	{
		perror(name);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (terminal)
			m = write(1, ":)$ ", 4);
		if (m == -1)
			handle_exit_failure((char **)command, name);
		read_line = custom_get_line(&command, &bufsize, STDIN_FILENO);
		if (read_line == (size_t)-1)
		{
			if (terminal)
				n = write(1, "\n", 1);
			if (n == -1)
				handle_exit_failure((char **)command, name);
			break;
		}
		i = 0;
		while (command[i])
		{
			if (command[i] == '\n')
			{
				command[i] = '\0';
				break;
			}
			i++;
		}
		process_id(argc, command, name);
	}
	free(command);
	return (0);
}
