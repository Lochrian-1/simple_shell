#include "shell.h"

/**
 * generate_tokens - tokenizes the input
 * @line: the input
 * @num_read: number of characters read
 *
 * Return: void
 */

char **generate_tokens(char *line, ssize_t num_read)
{
	char *cpy_line;
	char *delim = " \n";
	int num_tokens = 0, i = 0;
	char *token, **tokens;

	cpy_line = malloc(sizeof(char) * num_read);
	_strcpy(cpy_line, line);
	token = strtok(line, delim);
									
	while(token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;
	tokens = malloc(sizeof(char *) * num_tokens);
	token = strtok(cpy_line, delim);

	while(token != NULL)
	{
		tokens[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(tokens[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;

	return (tokens);
}
