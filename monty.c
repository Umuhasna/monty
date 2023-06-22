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
	unsigned int line_number = 1;
	char **array_of_tokens = NULL;

	if (argument_count != 2)
		error_message_no_args("USAGE: monty file\n");
	file = fopen(argument_values[1], "r");
	if (file == NULL)
		error_file_not_found(argument_values[1]);
	while ((read = getline(&line, &line_length, file)) != -1)
	{
		array_of_tokens = array_maker(line, " \n");
		if (array_of_tokens == NULL || array_of_tokens[0] == NULL)
		{
			free_array_of_tokens(array_of_tokens);
			line_number++;
			continue;
		}
		else if (is_opcode(array_of_tokens))
		{
			if (strcmp(array_of_tokens[0], "push") == 0)
				if (stack_push_handler(array_of_tokens, &line_number))
					continue;
			opcode_handler(array_of_tokens, NULL, line_number);
		}
		else
		{
			error_opcode_not_found(line_number, array_of_tokens[0]);
			free_array_of_tokens(array_of_tokens);
		}
		free_array_of_tokens(array_of_tokens);
		line_number++;
	}
	free_main_end(&line, &file);
	return (0);
}