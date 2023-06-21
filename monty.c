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
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argument_values[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argument_values[1]);
		exit(EXIT_FAILURE);
	}

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
					printf("Error: malloc failed\n");
					free_array_of_tokens(array_of_tokens);
					array_of_tokens = NULL;
					exit(EXIT_FAILURE);
				}
				if (array_of_tokens[1] != NULL)
				{
					new_node-> n = atoi(array_of_tokens[1]);
					new_node->prev = NULL;
					new_node->next = NULL;
					if( !opcode_handler(array_of_tokens, &new_node, line_number))
					{
						printf("Error: opcode failure\n");
					}
					free_array_of_tokens(array_of_tokens);
					array_of_tokens = NULL;
					continue;
				}
			}
			opcode_handler(array_of_tokens, NULL, line_number);
		}
		else
		{
			printf("L%d: unknown instruction %s\n",
					line_number, array_of_tokens[0]);
			free_array_of_tokens(array_of_tokens);
			array_of_tokens = NULL;
			exit(EXIT_FAILURE);
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
