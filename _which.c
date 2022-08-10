#include "shell.h"

/**
 * _getenv - Gets environment variable
 * @name: path name
 *
 * Return: void
 */

char *_getenv(const char *name)
{
	int i, j;
	int status;


	for (i = 0; environ[i] != NULL; i++)
	{
		status = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] != environ[i][j])
			{
				status = 0;
				break;
			}
		}
		if (status)
		{
			return (&environ[i][j + 1]);
		}
	}
	return (NULL);
}

/**
 * _which - checks the full path of cmd
 * @command: the command
 *
 * Return: void
 */

char *_which(char *command)
{
	char *path, *cpy_path, *path_token, *dir;
	int command_length, dir_length;
	struct stat testfile;

	if (command[0] == '/' || command[0] == '.')
	{
		if (stat(command, &testfile) == 0)
		{
			return (command);
		}
	}
	path = _getenv("PATH");
	if (path)
	{
		cpy_path = _strdup(path);
		command_length = _strlen(command);
		path_token = strtok(cpy_path, ":");
		while (path_token != NULL)
		{
			dir_length = _strlen(path_token);
			dir = malloc(dir_length + command_length + 2);
			_strcpy(dir, path_token);
			_strcat(dir, "/");
			_strcat(dir, command);
			_strcat(dir, "\0");
			if (stat(dir, &testfile) == 0)
			{
				free(cpy_path);
				return (dir);
			}
			free(dir);
			path_token = strtok(NULL, ":");
		}
		free(cpy_path);
		if (stat(command, &testfile) == 0)
			return (command);

		return (NULL);
	}
	return (NULL);
}
