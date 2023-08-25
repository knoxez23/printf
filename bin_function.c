#include "main.h"

/**
 * print_binary - handling binary specifier
 * @args: binary
 *Return: output
 */

int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int i, len = 0, bits[32], leading_zeros;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	for (i = 0; i < 32; i++)
	{
		bits[i] = num & 1;
		num >>= 1;
	}

	leading_zeros = 1;
	for (i = 31; i >= 0; i--)
	{
		if (bits[i] == 1)
		{
			leading_zeros = 0;
		}
		if (!leading_zeros)
		{
			_putchar('0' + bits[i]);
			len++;
		}
	}
	return (len);
}
