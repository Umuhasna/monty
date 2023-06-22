#include "monty.h"

/**
 * _list_length - short description
 *
 * Description: long description
 *
 * Return: return description
 */
int _list_length(void)
{
	stack_t *current;
	int count;

	current = top;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
