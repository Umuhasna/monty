#include "monty.h"

/**
 * malloc_char - short description
 *
 * Description: long description
 *
 * @string: reference to string
 * @size_of_malloc: int size of malloc
 * @file: string error message
 * @line: string
 *
 * Return: return description
 */
char *malloc_char(char **string, size_t size_of_malloc,
		FILE **file, char **line)
{
	*string = (char *) malloc(sizeof(char) * size_of_malloc);
	if (string == NULL)
	{
		free_main_end(line, file);
		error_message_no_args("Error: malloc failed\n");
	}
	return (*string);
}

/**
 * malloc_array - short description
 *
 * Description: long description
 *
 * @array: reference to string
 * @size_of_malloc: int size of malloc
 * @file: string error message
 * @line: string
 *
 * Return: return description
 */
char **malloc_array(char **array, size_t size_of_malloc,
		FILE **file, char **line)
{
	array = (char **) malloc(sizeof(char *) * size_of_malloc);
	if (array == NULL)
	{
		free_main_end(line, file);
		error_message_no_args("Error: malloc failed\n");
	}
	return (array);
}

/**
 * array_of_tokens_counter - short description
 *
 * Description: long description
 *
 * @array_of_tokens: reference to string
 *
 * Return: return description
 */
int array_of_tokens_counter(char **array_of_tokens)
{
	int count = 0;

	while (array_of_tokens[count])
		count++;
	return (count);
}
