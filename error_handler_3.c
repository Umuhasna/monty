#include "monty.h"

/**
 * error_stack_out_of_range - Printing custom error for not found command
 * @line_number: counter
 *
 * Return: void
 */
int error_stack_out_of_range(unsigned int line_number)
{
	char *error_str;
	char *line_number_str = _itoa(line_number);
	int size = strlen("L") + strlen(line_number_str) +
		strlen(": can't pchar, value out of range") + strlen("\n") + 1;

	malloc_char(&error_str, size, NULL, NULL);
	strcpy(error_str, "L");
	strcat(error_str, line_number_str);
	strcat(error_str, ": can't pchar, value out of range");
	strcat(error_str, "\n\0");

	fflush(stderr);
	write(STDERR_FILENO, error_str, strlen(error_str));
	free(error_str);
	free(line_number_str);
	exit(EXIT_FAILURE);
}

/**
 * error_stack_empty_pchar - Printing custom error for not found command
 * @line_number: counter
 *
 * Return: void
 */
int error_stack_empty_pchar(unsigned int line_number)
{
	char *error_str;
	char *line_number_str = _itoa(line_number);
	int size = strlen("L") + strlen(line_number_str) +
		strlen(": can't pchar, stack empty") + strlen("\n") + 1;

	malloc_char(&error_str, size, NULL, NULL);
	strcpy(error_str, "L");
	strcat(error_str, line_number_str);
	strcat(error_str, ": can't pchar, stack empty");
	strcat(error_str, "\n\0");

	fflush(stderr);
	write(STDERR_FILENO, error_str, strlen(error_str));
	free(error_str);
	free(line_number_str);
	exit(EXIT_FAILURE);
}
