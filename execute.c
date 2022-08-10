#include "shell.h"

/**
 * execute - excutes the command
 * @tokens: the parsed tokens
 *
 * Return: void
 */

int execute(char **tokens)
{
	pid_t child_pid;

	char *command, **envp;

	envp = environ;
	built_in(tokens);
	command = _which(tokens[0]);

	if (command == NULL)
	{
		return (-1);
	}
	child_pid = fork();

	if (child_pid == 0)
	{
		execve(command, tokens, envp);
		perror(tokens[0]);
		return (-1);
	}
	else if (child_pid > 0)
	{
		int status;

		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("Error ");
		return (-1);
	}
	return (0);
}
