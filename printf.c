#include "main.h"

/**
 * _printf - Custom version of the printf function
 * @format: Format string consisting of characters and specifiers
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    int char_count = 0;  // Count of characters printed
    va_list args;        // Argument list

    va_start(args, format);
    if (!format || (*format == '%' && *(format + 1) == '\0')) {
        return -1;
    }

    while (*format) {
        if (*format == '%') {
            format++; // Move to the specifier character
            switch (*format) {
                case 'c':
                    char_count += output_char(va_arg(args, int));
                    break;
                case 's':
                    char_count += output_string(va_arg(args, char *));
                    break;
                case '%':
                    output_char('%');
                    char_count++;
                    break;
                case 'd':
                case 'i':
                    char_count += output_number(va_arg(args, int));
                    break;
                default:
                    output_char('%');
                    char_count++;
                    if (*format) {
                        output_char(*format);
                        char_count++;
                    }
                    break;
            }
        } else {
            output_char(*format);
            char_count++;
        }
        format++;
    }

    va_end(args);
    return char_count;
}

