#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

void execute(char** args)
{
	if (strcmp(args[0], "cd") == 0)
	{
		chdir(args[1]);
	}
	else if ((strcmp(args[0], "exit") == 0))
	{		
		printf("Exiting shell...\n");
		exit(0);
	}
	else
	{
		if (fork() == 0)
		{
			int stat_code = execvp(args[0], args);

			if (stat_code == -1)
			{
				printf("Error: Your command terminated incorrectly\n");
				exit(1);
			}
		}
	}
}

char** parse(char* input)
{	
	int tokens_buf = 100;
	char** tokens = malloc(tokens_buf * sizeof(char*));
	int k = 0;

	int token_buf = 1024;
	char* token = malloc(token_buf * sizeof(char*));
	int l = 0;

	for (int i = 0; i < strlen(input); i++)
	{
		char character = input[i];
		
		if (character == ' ')
		{
			if (k + 1 > tokens_buf)
			{
				tokens_buf += 100;
				tokens = realloc(tokens, tokens_buf * sizeof(char*));
			}																									
			if (l + 1 >= token_buf)
			{
				token_buf += 1024;
				token = realloc(token, token_buf);
			}

			tokens[k] = token;
			k++;
			token = malloc(token_buf * sizeof(char*));
			l = 0;
		}
		else if (character == '\n')
		{
			if (k + 2 > tokens_buf)
			{
				tokens_buf += 100;
				tokens = realloc(tokens, tokens_buf * sizeof(char*));
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
	return tokens;
}

char* read_line()
{	
	char* buf;
	size_t bufsize = 100;
	size_t line;

	buf = (char*) malloc(bufsize * sizeof(char));
	if (buf == NULL)
	{
		printf("Error: Unable to allocate buffer");
		exit(1);
	}
	line = getline(&buf, &bufsize, stdin);
	
	return buf;
}

int main()
{
	printf("Welcome to Simple_Shell!\n");
	printf("\n");
	while (true)
	{
		char* input = read_line();
		char** parsed = parse(input);			                             
		
		execute(parsed);

		free(input);
		free(parsed);
	}	
	return 0;
}
