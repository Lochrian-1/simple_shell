#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

/**
 * _strcmp - compares two strings
 * @s1: The first string to compare
 * @s2: The second string to compare
 *
 * Return: void
 **/

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

/**
 * _strdup - returns a pointer which contains a copy of the string given
 * @str: the string variable
 *
 * Return: void
 */

char *_strdup(char *str)
{
	int length, i;
	char *arr;

	if (str == NULL)
	{
		return (NULL);
	}

	length = 0;
	while (*(str + length) != '\0')
	{
		length++;
	}

	arr = malloc(length * sizeof(char) + 1);
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
	{
		arr[i] = str[i];
	}
	arr[i] = '\0';

	return (arr);
}

/**
 * _strcat - concatenates two strings
 * @src: pointer to source
 * @dest: pointer at destination
 *
 * Return: void
 */

char *_strcat(char *dest, char *src)
{
	int a, b;

	a = 0;
	b = -1;
	while (dest[a] != '\0')
	{
		a++;
	}

	do {
		b++;
		dest[a] = src[b];
		a++;
	} while (src[b] != '\0');

	return (dest);
}
