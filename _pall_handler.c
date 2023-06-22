#include "monty.h"

/**
 * _print_number - short description
 *
 * Description: long description
 *
 * @line_number: argument_2 description
 *
 * Return: return description
 */
void _print_number(int line_number)
{
	char *number_str = _itoa(line_number);
	char *str;
	int size = strlen(number_str) + strlen("\n\0");

	str = (char *) malloc(sizeof(char) + size);
	if (str == NULL)
	{
		printf("malloc\n");
		exit(EXIT_FAILURE);
	}
	strcpy(str, number_str);
	strcat(str, "\n\0");
	fflush(stdout);
	write(STDOUT_FILENO, str, strlen(str));
	free(number_str);
	free(str);
}

/**
 * _pall_handler - short description
 *
 * Description: long description
 *
 * @stack: argument_1 description
 * @line_number: argument_2 description
 *
 * Return: return description
 */
void _pall_handler(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *current;

	current = top;
	while (current)
	{
		_print_number(current->n);
		current = current->next;
	}
}
