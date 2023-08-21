#include "main.h"

/**
 * _putchar - function to write character to standard output
 * @c: character
 * Return: output
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - print single character
 * @args: character
 * Return: output
 */
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_string - print string
 * @args: string
 * Return:  output
 */
int print_string(va_list args)
{
	int len = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		len += _printf("null");
	}
	while (*str)
	{
		len += _putchar(*str);
		str++;
	}
	return (len);
}

/**
 * _printf - main printf function
 * @format: specifier
 * Return: output
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			printed_chars += _putchar(format[i]);
		}
		else
		{
			i++;
			if (format[i] == '\0' || format[i] == ' ')
				return (-1);
			switch (format[i])
			{
				case 'c':
					printed_chars += print_char(args);
					break;
				case 's':
					printed_chars += print_string(args);
					break;
				case '%':
					printed_chars += _putchar('%');
					break;
				default:
					printed_chars += _putchar('%');
					printed_chars += _putchar(format[i]);
					break;
			}
		}
	}

	va_end(args);
	return (printed_chars);
}
