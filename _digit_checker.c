#include "monty.h"

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
	if (*number == '\0')
		return (0);

	if (*number == '-' || *number == '+')
	{
		number++;
		if (*number == '\0')
			return (0);
	}

	if (*number == '0')
		return (number[1] == '\0');

	while (*number != '\0')
	{
		if (!isdigit(*number))
			return (0);
		if (*number == '0' && *(number + 1) != '\0')
			return (0);
		number++;
	}
	return (1);
}
