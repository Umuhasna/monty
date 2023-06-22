#include "monty.h"

/**
 * _pchar_handler - short description
 *
 * Description: long description
 *
 * @stack: argument_1 description
 * @line_number: argument_2 description
 *
 * Return: return description
 */
void _pchar_handler(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	int asciiNumber = top->n;
	char character = (char) asciiNumber;

	write(STDOUT_FILENO, &character, 1);
	write(STDOUT_FILENO, "\n", 1);
}
