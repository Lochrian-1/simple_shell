#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * main - Creating a simple shell
 *
 * Return: void
 */

int main(void)
{
	char *line = NULL;
	size_t size = 0;
	int readsize = 0;

	write(STDIN_FILENO, "simple_shell$ ", 14);
	readsize = getline(&line, &size, stdin);
}
