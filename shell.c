#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * read_line - reads the input
 * @num_read: the number of lines read
 *
 * Return: buffer
 */

char *read_line(ssize_t *num_read)
{
	char *buffer = NULL;
	size_t n = 0;

	*num_read = getline(&buffer, &n, stdin);
	return (buffer);
}

/**
 * main - creates a simple shell
 *
 * Return: return_code
 */

int main(void)
{
	char *line_read, **tokens;
	ssize_t num_read;
	int return_code = 0;

	write(STDOUT_FILENO, "Welcome to Simple_Shell!\n", 25);
	_putchar('\n');

	while (1)
	{
		write(2, "$ ", 2);
		line_read = read_line(&num_read);

		if (num_read == -1)
		{
			write(2, "Exiting shell....\n", 18);
			exit(1);
		}
		tokens = generate_tokens(line_read, num_read);

		if (tokens[0] != NULL)
		{
			return_code = execute(tokens);
		}

		free(tokens);
		free(line_read);
	}
	return (return_code);
}
