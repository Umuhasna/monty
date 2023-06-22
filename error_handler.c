#include "monty.h"

/**
 * error_message_no_args - Printing custom error for not found command
 * @error_message: command-line args
 *
 * Return: void
 */
int error_message_no_args(char *error_message)
{
	int size = strlen(error_message);

	fflush(stderr);
	write(STDERR_FILENO, error_message, size);
	exit(EXIT_FAILURE);
}

/**
 * error_file_not_found - Printing custom error for not found command
 * @file_name: counter
 *
 * Return: void
 */
int error_file_not_found(char *file_name)
{
	char *error_str;
	int size = strlen("Error: Can't open file ") +
		strlen(file_name) + strlen("\n") + 1;

	malloc_char(&error_str, size, NULL, NULL);
	strcpy(error_str, "Error: Can't open file ");
	strcat(error_str, file_name);
	strcat(error_str, "\n\0");

	fflush(stderr);
	write(STDERR_FILENO, error_str, strlen(error_str));
	free(error_str);
	exit(EXIT_FAILURE);
}

/**
 * error_opcode_not_found - Printing custom error for not found command
 * @line_number: counter
 * @non_valid_opcode: string
 * @array_of_tokens: array
 * Return: void
 */
int error_opcode_not_found(unsigned int line_number, char *non_valid_opcode,
		char **array_of_tokens)
{
	char *error_str;
	char *line_number_str = _itoa(line_number);
	int size = strlen("L") + strlen(line_number_str) +
		strlen(": unknown instruction ") + strlen(non_valid_opcode)
		+ strlen("\n") + 1;

	malloc_char(&error_str, size, NULL, NULL);
	strcpy(error_str, "L");
	strcat(error_str, line_number_str);
	strcat(error_str, ": unknown instruction ");
	strcat(error_str, non_valid_opcode);
	strcat(error_str, "\n\0");

	fflush(stderr);
	write(STDERR_FILENO, error_str, strlen(error_str));
	free(error_str);
	free(line_number_str);
	free_array_of_tokens(array_of_tokens);
	exit(EXIT_FAILURE);
}

/**
 * error_push_non_digit - Printing custom error for not found command
 * @line_number: counter
 *
 * Return: void
 */
int error_push_non_digit(unsigned int line_number)
{
	char *error_str;
	char *line_number_str = _itoa(line_number);
	int size = strlen("L") + strlen(line_number_str) +
		strlen(": usage: push integer") + strlen("\n") + 1;

	malloc_char(&error_str, size, NULL, NULL);
	strcpy(error_str, "L");
	strcat(error_str, line_number_str);
	strcat(error_str, ": usage: push integer");
	strcat(error_str, "\n\0");

	fflush(stderr);
	write(STDERR_FILENO, error_str, strlen(error_str));
	free(error_str);
	free(line_number_str);
	exit(EXIT_FAILURE);
}

/**
 * error_stack_empty_pint - Printing custom error for not found command
 * @line_number: counter
 *
 * Return: void
 */
int error_stack_empty_pint(unsigned int line_number)
{
	char *error_str;
	char *line_number_str = _itoa(line_number);
	int size = strlen("L") + strlen(line_number_str) +
		strlen(": can't pint, stack empty") + strlen("\n") + 1;

	malloc_char(&error_str, size, NULL, NULL);
	strcpy(error_str, "L");
	strcat(error_str, line_number_str);
	strcat(error_str, ": can't pint, stack empty");
	strcat(error_str, "\n\0");

	fflush(stderr);
	write(STDERR_FILENO, error_str, strlen(error_str));
	free(error_str);
	free(line_number_str);
	exit(EXIT_FAILURE);
}
