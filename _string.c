#include "monty.h"

/**
 * rev_string - reverses a string
 * @str: the string
 *
 * Return: void
 */
void rev_string(char *str)
{
	int i, len;
	char tmp;

	len = 0;
	while (str[len] != '\0')
		len++;
	len--;
	for (i = 0; i < len; i++, len--)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
	}
}

/**
 * _itoa - converts int to a string
 * @command_num: number to convert
 *
 * Return: the converted integer
 */
char *_itoa(int command_num)
{
	char *str = malloc(sizeof(char) * (32 + 1));
	int i = 0;
	int is_negative = 0;

	if (str == NULL)
		error_message_no_args("Error: malloc failed\n");
	if (command_num < 0)
	{
		is_negative = 1;
		command_num = -(command_num);
	}
	do {
		str[i++] = command_num % 10 + '0';
		command_num /= 10;
	} while (command_num > 0);

	if (is_negative)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	rev_string(str);

	return (str);
}
