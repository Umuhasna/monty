#include "monty.h"

/**
 * _pop_handler - short description
 *
 * Description: long description
 *
 * @stack: argument_1 description
 * @line_number: argument_2 description
 *
 * Return: return description
 */
void _pop_handler(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *current;

	current = top;
	top = current->next;
	if (top != NULL)
		top->prev = NULL;
	free(current);
}
