#include "shell.h"

/**
 * built_in - checks for builtin cmd
 * @args: arguments
 *
 * Return: void
 */

void built_in(char **args)
{
	int num_builtins = 0, i;

	struct builtin builtins[] = {
		{"exit", shell_exit},
		{"cd", _cd},
		{"env", _env},
	};
	num_builtins = sizeof(builtins) / sizeof(struct builtin);

	for (i = 0; i < num_builtins; i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return;
		}
	}
}

/**
 * shell_exit - exits the shell
 * @args: arguments
 *
 * Return: void
 */

void shell_exit(char **args)
{
	(void)args;
	exit(0);
}

/**
 * _cd - changes working directory
 * @args: arguments
 *
 * Return: void
 */

void _cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("Error: cd: missing argument");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Error: cd");
		}
	}
}

/**
 * _env - checks for environment
 * @args: arguments
 *
 * Return: void 
 */ 

void _env(char **args)
{
	char **env = environ;

	while (*env)
	{
		write(STDOUT_FILENO,*env, _strlen(*env));
		*env++;
	}
	(void)args;
}