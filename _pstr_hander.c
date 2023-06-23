#include "monty.h"

/**
 * _pstr_handler - short description
 *
 * Description: long description
 *
 * @stack: argument_1 description
 * @line_number: argument_2 description
 *
 * Return: return description
 */
void _pstr_handler(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *current;
	int asciiNumber;
	char character;

	current = top;
	while (current)
	{
		asciiNumber = current->n;
		if (asciiNumber == 0)
			break;
		if (asciiNumber < 0 || asciiNumber > 127)
			break;
		character = (char) asciiNumber;
		write(STDOUT_FILENO, &character, 1);
		current = current->next;
	}
	write(STDOUT_FILENO, "\n", 1);
}
