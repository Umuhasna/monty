#include "monty.h"

/**
 * error_stack_empty_pop - Printing custom error for not found command
 * @line_number: counter
 *
 * Return: void
 */
int error_stack_empty_pop(unsigned int line_number)
{
	char *error_str;
	char *line_number_str = _itoa(line_number);
	int size = strlen("L") + strlen(line_number_str) +
		strlen(": can't pop an empty stack") + strlen("\n") + 1;

	malloc_char(&error_str, size, NULL, NULL);
	strcpy(error_str, "L");
	strcat(error_str, line_number_str);
	strcat(error_str, ": can't pop an empty stack");
	strcat(error_str, "\n\0");

	fflush(stderr);
	write(STDERR_FILENO, error_str, strlen(error_str));
	free(error_str);
	free(line_number_str);
	exit(EXIT_FAILURE);
}

/**
 * error_swap - Printing custom error for not found command
 * @line_number: counter
 *
 * Return: void
 */
int error_swap(unsigned int line_number)
{
	char *error_str;
	char *line_number_str = _itoa(line_number);
	int size = strlen("L") + strlen(line_number_str) +
		strlen(": can't swap, stack too short") + strlen("\n") + 1;

	malloc_char(&error_str, size, NULL, NULL);
	strcpy(error_str, "L");
	strcat(error_str, line_number_str);
	strcat(error_str, ": can't swap, stack too short");
	strcat(error_str, "\n\0");

	fflush(stderr);
	write(STDERR_FILENO, error_str, strlen(error_str));
	free(error_str);
	free(line_number_str);
	exit(EXIT_FAILURE);
}

/**
 * error_add - Printing custom error for not found command
 * @line_number: counter
 *
 * Return: void
 */
int error_add(unsigned int line_number)
{
	char *error_str;
	char *line_number_str = _itoa(line_number);
	int size = strlen("L") + strlen(line_number_str) +
		strlen(": can't add, stack too short") + strlen("\n") + 1;

	malloc_char(&error_str, size, NULL, NULL);
	strcpy(error_str, "L");
	strcat(error_str, line_number_str);
	strcat(error_str, ": can't add, stack too short");
	strcat(error_str, "\n\0");

	fflush(stderr);
	write(STDERR_FILENO, error_str, strlen(error_str));
	free(error_str);
	free(line_number_str);
	exit(EXIT_FAILURE);
}

/**
 * error_opp - Printing custom error for not found command
 * @line_number: counter
 * @op: op
 *
 * Return: void
 */
int error_opp(unsigned int line_number, char *op)
{
	char *error_str;
	char *line_number_str = _itoa(line_number);
	int size = strlen("L") + strlen(line_number_str) +
		strlen(": can't ") + strlen(op) +
		strlen(", stack too short") + strlen("\n") + 1;

	malloc_char(&error_str, size, NULL, NULL);
	strcpy(error_str, "L");
	strcat(error_str, line_number_str);
	strcat(error_str, ": can't ");
	strcat(error_str, op);
	strcat(error_str, ", stack too short");
	strcat(error_str, "\n\0");

	fflush(stderr);
	write(STDERR_FILENO, error_str, strlen(error_str));
	free(error_str);
	free(line_number_str);
	exit(EXIT_FAILURE);
}

/**
 * error_divion_by_zero - Printing custom error for not found command
 * @line_number: counter
 *
 * Return: void
 */
int error_divion_by_zero(unsigned int line_number)
{
	char *error_str;
	char *line_number_str = _itoa(line_number);
	int size = strlen("L") + strlen(line_number_str) +
		strlen(": division by zero") + strlen("\n") + 1;

	malloc_char(&error_str, size, NULL, NULL);
	strcpy(error_str, "L");
	strcat(error_str, line_number_str);
	strcat(error_str, ": division by zero");
	strcat(error_str, "\n\0");

	fflush(stderr);
	write(STDERR_FILENO, error_str, strlen(error_str));
	free(error_str);
	free(line_number_str);
	exit(EXIT_FAILURE);
}
