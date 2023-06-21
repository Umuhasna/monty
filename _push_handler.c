#include "monty.h"

/**
 * _push_handler - short description
 *
 * Description: long description
 *
 * @stack: argument_1 description
 * @line_number: argument_2 description
 *
 * Return: return description
 */
void _push_handler(stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	if (top == NULL)
	{
		top = *stack;
		return;
	}
	else
	{
		(*stack)->next = top;
		top->prev = *stack;
		top = *stack;
		return;
	}
}
