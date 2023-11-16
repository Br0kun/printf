#include "main.h"
/**
 * _printf - produces output according to a format specifier
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	if (!format || !format[0] || (*format == '%' && *(format + 1) == '\0'))
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += _putchar(va_arg(args, int));
			else if (*format == 's')
				count += handle_string(va_arg(args, char*));
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'd' || *format == 'i')
				count += handle_number(va_arg(args, int));
			else
			{
				_putchar('%');
				count++;
				if (*format)
				{
					_putchar(*format);
					count++;
				}
			} format++;
		}
		else
		{
			_putchar(*format);
			count++;
			format++;
		}
	} return (count);
}
