/**
 * It prints the provided string followed by a newline character.
 * @str: the string to be printed.
 *
 * Return: void
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * It writes the character 'c' to the standard output (stdout).
 * @c: the character to be printed.
 * Return: On success, 1 is returned. On error, -1 is returned and the errno variable is set appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
