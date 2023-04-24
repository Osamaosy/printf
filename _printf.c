#include "main.h"
/**
* _printf - Printf function
* @format: format string
* Return: number of printed characters
*/
int _printf(const char *format, ...)
{
	int i = 0, printed_chars = 0, buff_ind = 0, flags, width, precision, size;
	int printed;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
			}
			printed_chars++;
		}
		else
		{
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i args, buffer, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
			if (buff_ind > BUFF_SIZE - 50)
			{
				print_buffer(buffer, &buff_ind);
			}
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(args);

	return (printed_chars);
}

/**
* print_buffer - Prints the contents of the buffer if it is full
* @buffer: Array of characters
* @buff_ind: Index at which to add next character, represents the length
*/
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
		*buff_ind = 0;
	}
}
