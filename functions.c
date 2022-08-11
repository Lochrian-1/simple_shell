#include "main.h"

/**
 * ch - function to return char
 * @character: list given
 *
 * Return: number of char printed
 */

int ch(va_list character)
{
	return (_putchar(va_arg(character, int)));
}

/**
 * str - prints string to stdout
 * @string: list
 *
 * Return: number of char
 */

int str(va_list string)
{
	int len;
	char *str;

	str = va_arg(string, char *);

	if (str == NULL)
		str = "(null)";
	len = 0;

	while (str[len] != '\0')
		len = len + _putchar(str[len]);
	return (len);
}

/**
 * _int - function to print integers
 * @integer: list printed
 *
 * Return: Return count
 */

int _int(va_list integer)
{
	int a, exp = 1, len = 0;
	unsigned int n;

	a = va_arg(integer, int);

	if (a < 0)
	{
		len = len + _putchar('-');
		n = a * -1;
	}
	else
		n = a;

	while (n / exp > 9)
		exp *= 10;

	while (exp != 0)
	{
		len = len + _putchar(n / exp + '0');
		n = n % exp;
		exp = exp / 10;
	}
	return (len);
}
