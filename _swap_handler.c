#include "monty.h"

/**
 * _swap_handler - short description
 *
 * Description: long description
 *
 * @stack: argument_1 description
 * @line_number: argument_2 description
 *
 * Return: return description
 */
void _swap_handler(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *current, *current_next;
	int temp;

	current = top;
	current_next = top->next;
	temp = current->n;
	current->n = current_next->n;
	current_next->n = temp;
}
