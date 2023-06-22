#include "monty.h"

/**
 * malloc_char - short description
 *
 * Description: long description
 *
 * @string: reference to string
 * @size_of_malloc: int size of malloc
 * @error_message: string error message
 *
 * Return: return description
 */
char *malloc_char(char **string, size_t size_of_malloc,
		__attribute((unused)) char *error_message)
{
	*string = (char *) malloc(sizeof(char) * size_of_malloc);
	if (string == NULL)
	{
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
 * @error_message: string error message
 *
 * Return: return description
 */
char **malloc_array(char **array, size_t size_of_malloc,
		__attribute((unused)) char *error_message)
{
	array = (char **) malloc(sizeof(char *) * size_of_malloc);
	if (array == NULL)
	{
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
