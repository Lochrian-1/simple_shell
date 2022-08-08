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
	char *line = NULL, *token, *cpyline = NULL;
	char **argv;
	size_t size = 0;
	ssize_t readsize;
	int numtokens = 0, count = 0;

	write(STDIN_FILENO, "simple_shell$ ", 14);
	readsize = getline(&line, &size, stdin);

	cpyline = malloc(sizeof(char) * readsize);
	_strcpy(cpyline, line);

	token = strtok(line, " \n");

	while (token != NULL)
	{
		numtokens++;
		token = strtok(NULL, " \n");
	}
	numtokens++;

	argv = malloc(sizeof(char *) * numtokens);

	token = strtok(cpyline, " \n");
	while (token != NULL)
	{
		argv[count] = malloc(sizeof(char) * _strlen(token));
		_strcpy(argv[count], token);
		count++;
		token = strtok(NULL, " \n");
	}
	argv[count] = NULL;
}
