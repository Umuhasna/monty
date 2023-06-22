#include "monty.h"

/**
 * is_opcode - short description
 *
 * Description: long description
 *
 * @array_of_tokens: command array
 *
 * Return: 1 if success 0 if failure
 */
int is_opcode(char **array_of_tokens)
{
	int opcode_index;
	const instruction_t opcodes[] = {
		{"push", _push_handler},
		{"pall", _pall_handler},
		{NULL, NULL}
	};

	if (array_of_tokens == NULL)
		return (0);
	if (array_of_tokens[0] == NULL)
		return (0);

	for (opcode_index = 0; opcodes[opcode_index].opcode != NULL;
			opcode_index++)
		if (strcmp(array_of_tokens[0],
					opcodes[opcode_index].opcode) == 0)
			return (1);
	return (0);
}

/**
 * opcode_handler - short description
 *
 * Description: long description
 *
 * @array_of_tokens: command array
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: 1 if success 0 if failure
 */
int opcode_handler(char **array_of_tokens,
		stack_t **stack, unsigned int line_number)
{
	int opcode_index;
	const instruction_t opcodes[] = {
		{"push", _push_handler},
		{"pall", _pall_handler},
		{NULL, NULL}
	};
	if (array_of_tokens == NULL)
		return (0);
	if (array_of_tokens[0] == NULL)
		return (0);

	for (opcode_index = 0; opcodes[opcode_index].opcode != NULL;
			opcode_index++)
	{
		if (strcmp(array_of_tokens[0],
					opcodes[opcode_index].opcode) == 0)
		{
			opcodes[opcode_index].f(stack, line_number);
			return (1);
		}
	}
	return (0);
}