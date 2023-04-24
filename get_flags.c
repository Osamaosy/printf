#include "main.h"

/**
 * get_flags -is to Calculates active flags
 * @formt: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 *
 *
 */
int get_flags(const char *formt, int *i)
{
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; formt[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (formt[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}

get_precision.c


#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @formt: Formatted string in which to print the arguments
 * @i: List of all arguments to be printed.
 * @list: list of all arguments.
 *
 * Return: Precision.
 *
 */
int get_precision(const char *formt, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (formt[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; formt[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(formt[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (formt[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
