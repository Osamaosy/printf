#include "main.h"

/**
* _puts - is to print a string
* @s : is the strig
*
* Return: void
*/
int _puts(char *s)
{
char *a = s;

	while (*s)
	_putchar (*s++);
	return (s - a);
}

/**
* _putchar - is to do that write the carcter ch to stdout
* @ch : the charcter
*
* Return: one success 1.
* when error return -1
*/
int _putchar(int ch)
{
	static int J;

	static char bf[OUTPUT_BUF_SIZE];

	if (ch == BUF_FULS || J >= OUTPUT_BUF_SIZE)
	{
	  write(1, bf, J);
	  J = 0;
	}
	if (ch != BUF_FLUSH)
	   bf[J++] = c;
	return (1);
}
