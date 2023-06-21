#include "monty.h"

/**
 * free_linked_list - short description
 *
 * Description: long description
 *
 * Return: return description
 */
void free_linked_list(void)
{
	stack_t *current;
	stack_t *previous;

	current = top;
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
}

/**
 * free_array_of_tokens - free array of tokens in the main function
 * @array_of_tokens: tokenized string
 *
 * Return: void
 */
void free_array_of_tokens(char **array_of_tokens)
{
	int index;

	for (index = 0; array_of_tokens[index]; index++)
		free(array_of_tokens[index]);
	free(array_of_tokens);
}
