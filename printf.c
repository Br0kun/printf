#include "main.h"
/*
 * _printf - Custom printf-like function
 * @format: Format string containing specifiers
 * Return: Total number of characters printed
 */
int _printf(const char *format, ...)
{
int total_chars = 0; /*Total characters printed */
va_list args_list; /*List for variable arguments */
va_start(args_list, format);
if (!format || !format[0] || (*format == '%' && !*(format + 1)))
{
return (-1);
}
for (const char *current_char = format; *current_char; current_char++)
{
if (*current_char == '%')
{
current_char++;
switch (*current_char)
{
case 'c':
total_chars += print_character(va_arg(args_list, int));
break;
case 's':
total_chars += print_str(va_arg(args_list, char *);
break;
case '%':
total_chars += print_percent_sign();
break;
case 'd':
case 'i':
total_chars += print_integer(va_arg(args_list, int));
break;
default:
total_chars += print_unhandled_specifier(current_char);
break;  
}
}
else
{
print_character(*current_char);
total_chars++;
}
}
va_end(args_list);
return (total_chars);
}
