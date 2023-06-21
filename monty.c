#include "monty.h"

stack_t *top = NULL;

/**
 * main - short description
 *
 * Description: long description
 *
 * @argument_count: argument_1 description
 * @argument_values: argument_2 description
 *
 * Return: return description
 */
int main(int argument_count, char **argument_values)
{
	FILE *file;
	char *line = NULL;
	size_t line_length = 0;
	ssize_t read = 0;
	int line_number = 1;
	char **array_of_tokens = NULL;
	stack_t *new_node = NULL;

	if (argument_count != 2)
		error_message_no_args("USAGE: monty file\n");

	file = fopen(argument_values[1], "r");
	if (file == NULL)
		error_file_not_found(argument_values[1]);

	while ((read = getline(&line, &line_length, file)) != -1)
	{
		array_of_tokens = array_maker(line, " \n");
		if (is_opcode(array_of_tokens))
		{
			if (strcmp(array_of_tokens[0], "push") == 0)
			{
				new_node = (stack_t *) malloc(sizeof(stack_t));
				if (new_node == NULL)
				{
					free_array_of_tokens(array_of_tokens);
					error_message_no_args("Error: malloc failed\n");
				}
				if (array_of_tokens[1] != NULL)
				{
					new_node-> n = atoi(array_of_tokens[1]);
					new_node->prev = NULL;
					new_node->next = NULL;
					if (!opcode_handler(array_of_tokens, &new_node, line_number))
						error_message_no_args("Error: opcode failure\n");
					free_array_of_tokens(array_of_tokens);
					array_of_tokens = NULL;
					continue;
				}
			}
			opcode_handler(array_of_tokens, NULL, line_number);
		}
		else
		{
			free_array_of_tokens(array_of_tokens);
			error_opcode_not_found(line_number, array_of_tokens[0]);
		}
		free_array_of_tokens(array_of_tokens);
		array_of_tokens = NULL;
		line_number++;
	}
	free_linked_list();
	fclose(file);
	free(line);

	return (0);
}
