#include "monty.h"

void no_betty(void);
stack_t *top;

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

	top = NULL;
	if (argument_count != 2)
		error_message_no_args("USAGE: monty file\n");
	file = fopen(argument_values[1], "r");
	if (file == NULL)
		error_file_not_found(argument_values[1]);
	while ((read = getline(&line, &line_length, file)) != -1)
	{
		array_of_tokens = array_maker(line, " \n");
		if (array_of_tokens != NULL &&  array_of_tokens[0] != NULL)
		{
			if (is_opcode(array_of_tokens))
			{
				if (strcmp(array_of_tokens[0], "push") == 0)
					if (stack_push_handler(array_of_tokens,
								&line_number, &line, &file))
						continue;
				if (strcmp(array_of_tokens[0], "pint") == 0)
					if (top == NULL)
					{
						free_array_of_tokens(array_of_tokens);
						free_main_end(&line, &file);
						error_stack_empty_pint(line_number);
					}
				if (strcmp(array_of_tokens[0], "pop") == 0)
					if (top == NULL)
					{
						free_array_of_tokens(array_of_tokens);
						free_main_end(&line, &file);
						error_stack_empty_pop(line_number);
					}
				if (strcmp(array_of_tokens[0], "swap") == 0)
					if (_list_length() < 2)
					{
						free_array_of_tokens(array_of_tokens);
						free_main_end(&line, &file);
						error_swap(line_number);
					}
				if (strcmp(array_of_tokens[0], "add") == 0)
					if (_list_length() < 2)
					{
						free_array_of_tokens(array_of_tokens);
						free_main_end(&line, &file);
						error_add(line_number);
					}
				if (strcmp(array_of_tokens[0], "nop") != 0)
					opcode_handler(array_of_tokens, NULL, line_number);
			}
			else
			{
				free_main_end(&line, &file);
				error_opcode_not_found(line_number, array_of_tokens[0],
						array_of_tokens);
			}
		}
		free_array_of_tokens(array_of_tokens);
		free(line);
		line = NULL;
		line_number++;
	}
	free_main_end(&line, &file);
	return (0);
}

/**
 * do_betty - do betts
 * Return: void
 */
void do_betty(void)
{
}
