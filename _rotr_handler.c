#include "monty.h"

/**
 * _rotr_handler - short description
 *
 * Description: long description
 *
 * @stack: argument_1 description
 * @line_number: argument_2 description
 *
 * Return: return description
 */
void _rotr_handler(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *old_tail, *old_top;

	if (_list_length() >= 2)
	{
		old_top = top;
		old_tail = top;
		while (old_tail)
		{
			if (old_tail->next == NULL)
			{
				old_tail->prev->next = NULL;
				old_tail->next = old_top;
				old_tail->prev = NULL;
				old_top->prev = old_tail;
				top = old_tail;
				break;
			}
			old_tail = old_tail->next;
		}
	}
}
