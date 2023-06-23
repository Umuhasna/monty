#include "monty.h"

/**
 * _qpush_handler - short description
 *
 * Description: long description
 *
 * @stack: argument_1 description
 * @line_number: argument_2 description
 *
 * Return: return description
 */
void _qpush_handler(stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *current;

	if (top == NULL)
	{
		top = *stack;
	}
	else
	{
		current = top;
		while (current)
		{
			if (current->next == NULL)
			{
				(*stack)->prev = current;
				current->next = *stack;
				break;
			}
			current = current->next;
		}
	}
}
