#include "shell.h"
#include "strfunc.c"
#include "_putchar.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

char **environ;

/**
 * execute - Executes the tokens
 * @args: arguments
 *
 * Return: void
 */

void execute(char **args)
{
	char *env_args[] = { "PATH=/bin", "USER=me", NULL };

	if (_strcmp(args[0], "cd") == 0)
	{
		chdir(args[1]);
	}
	else if ((_strcmp(args[0], "exit") == 0))
	{
		write(STDOUT_FILENO, "Exiting shell...\n", 17);
		exit(0);
	}
	else
	{
		if (fork() == 0)
		{
			int stat_code = execve(args[0], args, env_args);

			if (stat_code == -1)
			{
				write(STDOUT_FILENO, "Error: Your command terminated incorrectly\n", 43);
				exit(1);
			}
		}
	}
}

/**
 * parse - Tokenization of input
 * @input: input
 *
 * Return: tokens
 */

char **parse(char *input)
{
	int tokens_buf = 100;
	char **tokens = malloc(tokens_buf * sizeof(char *));
	int k = 0;

	int token_buf = 1024;
	char *token = malloc(token_buf * sizeof(char *));
	int l = 0;

	for (int i = 0; i < _strlen(input); i++)
	{
		char character = input[i];

		if (character == ' ')
		{
			if (k + 1 > tokens_buf)
			{
				tokens_buf += 100;
				tokens = realloc(tokens, tokens_buf * sizeof(char *));
			}
			if (l + 1 >= token_buf)
			{
				token_buf += 1024;
				token = realloc(token, token_buf);
			}

			tokens[k] = token;
			k++;
			token = malloc(token_buf * sizeof(char *));
			l = 0;
		}
		else if (character == '\n')
		{
			if (k + 2 > tokens_buf)
			{
				tokens_buf += 100;
				tokens = realloc(tokens, tokens_buf * sizeof(char *));
			}

			if (l + 1 > token_buf)
			{
				token_buf += 1024;
				token = realloc(token, token_buf);
			}
			tokens[k] = token;
			k++;
			tokens[k] = NULL;
			break;
		}
		else
		{
			if (l + 1 > token_buf)
			{
				token_buf += 1024;
				token = realloc(token, token_buf);
			}

			token[l] = character;
			l++;
		}
	}
	return (tokens);
}

/**
 * read_line - Reads the input
 *
 * Return: buffer
 */

char *read_line(void)
{
	char *buf;
	size_t bufsize = 100;
	size_t line;

	buf = (char *) malloc(bufsize * sizeof(char));
	if (buf == NULL)
	{
		write(STDOUT_FILENO, "Error: Unable to allocate buffer", 32);
		exit(1);
	}
	line = getline(&buf, &bufsize, stdin);
	return (buf);
}

/**
 * main - Creates a simple shell
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	write(STDOUT_FILENO, "Welcome to Simple_Shell!\n", 25);
	_putchar('\n');
	while (true)
	{
		char *input = read_line();
		char **parsed = parse(input);

		execute(parsed);

		free(input);
		free(parsed);
	}
	return (0);
}
