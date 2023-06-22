#include "monty.h"

/**
 * stack_push_handler - short description
 *
 * Description: long description
 *
 * @array_of_tokens: argument_1 description
 * @line_number: argument_2 description
 * @file: file stream
 * @line: line pointer
 *
 * Return: return description
 */
int stack_push_handler(char **array_of_tokens, unsigned int *line_number,
		char **line, FILE **file)
{
	stack_t *new_node;

	new_node = (stack_t *) malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free_array_of_tokens(array_of_tokens);
		free_main_end(line, file);
		error_message_no_args("Error: malloc failed\n");
	}
	if (array_of_tokens[1] != NULL)
	{
		if (!is_number(array_of_tokens[1]))
		{
			free_array_of_tokens(array_of_tokens);
			free_main_end(line, file);
			free(new_node);
			error_push_non_digit(*line_number);
		}
		new_node->n = atoi(array_of_tokens[1]);
		new_node->prev = NULL;
		new_node->next = NULL;
		opcode_handler(array_of_tokens, &new_node, *line_number);
		free_array_of_tokens(array_of_tokens);
		array_of_tokens = NULL;
		*line_number = *line_number + 1;
		return (1);
	}
	else
	{
		free_array_of_tokens(array_of_tokens);
		free_main_end(line, file);
		free(new_node);
		error_push_non_digit(*line_number);
	}
	return (0);
}
