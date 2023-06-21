#include "monty.h"

/**
 * _pall_handler - short description
 *
 * Description: long description
 *
 * @stack: argument_1 description
 * @line_number: argument_2 description
 *
 * Return: return description
 */
void _pall_handler(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *current;

	current = top;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
