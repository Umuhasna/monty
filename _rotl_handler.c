#include "monty.h"

/**
 * _rotl_handler - short description
 *
 * Description: long description
 *
 * @stack: argument_1 description
 * @line_number: argument_2 description
 *
 * Return: return description
 */
void _rotl_handler(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *old_tail, *old_top, *new_top;

	if (_list_length() >= 2)
	{
		old_top = top;
		new_top = top->next;
		old_tail = top;
		while (old_tail)
		{
			if (old_tail->next == NULL)
			{
				old_top->prev = old_tail;
				old_tail->next = old_top;
				old_top->next = NULL;
				new_top->prev = NULL;
				top = new_top;
				break;
			}
			old_tail = old_tail->next;
		}
	}
}
