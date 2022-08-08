#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * _strcat - concatenates two strings
 * @dest: destination char
 * @src: source char
 *
 * Return: pathname
 */

char *_strcat(char *dest, char *src)
{
	int i, n = 0;

	while (dest[n] != '\0')
	{
		n++;
	}

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[n + i] = src[i];
		dest[n + i] = '\0';
	}
	return (dest);
}

/**
 * _strlen - returns length of string
 * @s: string
 *
 * Return: length of string
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * *_strcpy - copies the string being pointed at
 * @dest: a char type string
 * @src: a char type string
 *
 * Return: void
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (*(src + i))
	{
		dest[i] = *(src + i);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char **environ;

/**
 * main - Creating a simple shell
 *
 * Return: void
 */

int main(void)
{
	char *line = NULL, *token, *cpyline = NULL, *path;
	char **argv;
	size_t size = 0;
	ssize_t readsize;
	int numtokens = 0, count = 0;

	write(STDIN_FILENO, "simple_shell$ ", 14);
	readsize = getline(&line, &size, stdin);

	if (readsize == -1)
	{
		write(STDIN_FILENO, "Exiting shell... \n", 18);
		return (-1);
	}

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

	path = _strcat("/usr/bin/", argv[0]);

	if (execve(path, argv, environ) == -1)
	{
		perror("Error ");
	}
}
