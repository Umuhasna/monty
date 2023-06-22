#include "monty.h"

/**
 * _sub_handler - short description
 *
 * Description: long description
 *
 * @stack: argument_1 description
 * @line_number: argument_2 description
 *
 * Return: return description
 */
void _sub_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *current_next;

	current_next = top->next;
	current_next->n = current_next->n - top->n;
	_pop_handler(stack, line_number);
}
