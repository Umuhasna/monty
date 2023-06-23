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
			return;
		if (asciiNumber < 0 || asciiNumber > 127)
			return;
		character = (char) asciiNumber;
		write(STDOUT_FILENO, &character, 1);
		write(STDOUT_FILENO, "\n", 1);
		current = current->next;
	}
}
