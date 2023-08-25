#include "main.h"

/**
 * print_unsigned - print unsigned
 * @args: unsigned
 * Return: output
 */

int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0, num_digits;
	unsigned int temp, divisor, digit;
	int i;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
		temp = num;
		num_digits = 0;

		while (temp > 0)
		{
			temp /= 10;
			num_digits++;
		}
		while (num_digits > 0)
		{
			divisor = 1;

			for (i = 1; i < num_digits; i++)
			{
				divisor *= 10;
			}
			if (num == 0)
			{
				break;
			}
			digit = (num / divisor) % 10;
			_putchar('0' + digit);
			len++;
			num_digits--;
		}
	return (len);
}

/**
 * print_octal - print octal
 * @args: octal
 * Return: output
 */

int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0;

	if (num == 0)
	{
		len += _putchar('0');
	}
	else
	{
		char octal[50];
		int i = 0;

		while (num > 0)
		{
			octal[i] = (num % 8) + '0';
			num /= 8;
			i++;
		}
		for (i = i - 1; i >= 0; i--)
		{
			_putchar(octal[i]);
			len++;
		}
	}
	return (len);
}

/**
 * print_hex - print hex
 * @args: hex
 * @uppercase: ...
 * Return: output
 */

int print_hex(va_list args, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0;

	if (num == 0)
	{
		len += _putchar('0');
	}
	else
	{
		char hex[50];
		int i = 0;

		while (num > 0)
		{
			int remainder = num % 16;

			if (uppercase)
			{
				hex[i] = (remainder < 10) ? remainder + '0' : (remainder - 10) + 'A';
			}
			else
			{
				hex[i] = (remainder < 10) ? remainder + '0' : (remainder - 10) + 'a';
			}
			num /= 16;
			i++;
		}
		for (i = i - 1; i >= 0; i--)
		{
			_putchar(hex[i]);
			len++;
		}
	}
	return (len);
}

/**
 * print_hex_lower - hex lower
 * @args: hex lower
 * Return: output
 */

int print_hex_lower(va_list args)
{
	return (print_hex(args, 0));
}

/**
 * print_hex_upper - hex upper
 * @args: hex
 * Return: output
 */

int print_hex_upper(va_list args)
{
	return (print_hex(args, 1));
}
