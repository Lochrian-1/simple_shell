#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

struct builtin {
	char *name;
	void (*func)(char **args);
};

char **generate_tokens(char *line, ssize_t num_read);
int execute(char **tokens);
void built_in(char **args);
void shell_exit(char **args);
void _cd(char **args);
void _env(char **args);
char *_which(char *command);
int _putchar(char c);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);

#endif
