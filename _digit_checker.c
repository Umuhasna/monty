#include "monty.h"

/**
 * is_digit - short description
 *
 * Description: long description
 *
 * @number: argument_1 description
 *
 * Return: return description
 */
int is_digit(char number)
{
	return (number >= '0' && number <= '9');
}

/**
 * is_number - short description
 *
 * Description: long description
 *
 * @number: argument_1 description
 *
 * Return: return description
 */
int is_number(char *number)
{
	int index = 0;

	if (number == NULL)
		return (0);
	if (*number == '\0')
		return (0);

	if (*number == '-' || *number == '+')
	{
		index++;
		if (*number == '\0')
			return (0);
	}

	if (number[index] == '0')
		return (number[index + 1] == '\0');

	while (number[index] != '\0')
	{
		if (!is_digit(number[index]))
			return (0);
		index++;
	}
	return (1);
}
