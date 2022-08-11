#include "main.h"

/**
  * _hex_str - converts from base 10 to hex
  * @n: number
  * @hex: base of 16
  * @alpha: Letters a to f (upper and lower)
  *
  * Return: number of chars
  */

int _hex_str(unsigned int n, unsigned int hex, char alpha)
{
	unsigned int a = n % hex;
	unsigned int b = n / hex;
	char c;

	if (a > 10)
		c = (a - 10) + alpha;
	else
		c = a + '0';
	if (b == 0)
	{
		return (_putchar(c));
	}
	if (b < hex)
	{
		if (b > 10)
			return (_putchar(b - 10 + alpha) + _putchar(c));
		return (_putchar(b + '0') + _putchar(c));
	}
	return (_hex_str(b, hex, alpha) + _putchar(c));
}

/**
 * _uint - unsigned int
 * @unsign: ar being passed
 *
 * Return: number of chars
 */

int _uint(va_list unsign)
{
	unsigned int n;
	int exp = 1;
	int len = 0;

	n = va_arg(unsign, unsigned int);

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

/**
 * _uoct - print octal
 * @oct: ar being passed
 *
 * Return: number of chars
 */

int _uoct(va_list oct)
{
	int count = 0, i;
	int *arr;
	unsigned int n = va_arg(oct, unsigned int);
	unsigned int temp = n;

	while (n / 8 != 0)
	{
		n /= 8;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));
	for (i = 0; i < count; i++)
	{
		arr[i] = temp % 8;
		temp /= 8;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}

/**
 * _lowhex - print lowercase
 * @hexadecimal: argument
 *
 * Return: number of chars
 */

int _lowhex(va_list hexadecimal)
{
	return (_hex_str(va_arg(hexadecimal, unsigned int), 16, 'a'));
}

/**
 * _uphex - print uppercase
 * @hexadecimal: argument
 *
 * Return: number of chars
 */

int _uphex(va_list hexadecimal)
{
	return (_hex_str(va_arg(hexadecimal, unsigned int), 16, 'A'));
}


