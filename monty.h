#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *top;

char *malloc_char(char **string, size_t size_of_malloc,
		FILE **file, char **line);
char **malloc_array(char **array, size_t size_of_malloc,
		FILE **file, char **line);
char **array_maker(char *input, char *delimiter, FILE **file, char **line);
int is_opcode(char **array_of_tokens);
int opcode_handler(char **array_of_tokens,
		stack_t **stack, unsigned int line_number);
void _push_handler(stack_t **stack, unsigned int line_number);
void _qpush_handler(stack_t **stack, unsigned int line_number);
void _pall_handler(stack_t **stack, unsigned int line_number);
void _pint_handler(stack_t **stack, unsigned int line_number);
void _pop_handler(stack_t **stack, unsigned int line_number);
void _swap_handler(stack_t **stack, unsigned int line_number);
void _add_handler(stack_t **stack, unsigned int line_number);
void _sub_handler(stack_t **stack, unsigned int line_number);
void _div_handler(stack_t **stack, unsigned int line_number);
void _mul_handler(stack_t **stack, unsigned int line_number);
void _mod_handler(stack_t **stack, unsigned int line_number);
void _nop_handler(stack_t **stack, unsigned int line_number);
void _pchar_handler(stack_t **stack, unsigned int line_number);
void _pstr_handler(stack_t **stack, unsigned int line_number);
void _rotl_handler(stack_t **stack, unsigned int line_number);
void _rotr_handler(stack_t **stack, unsigned int line_number);
void free_linked_list(void);
void free_array_of_tokens(char **array_of_tokens);
void free_main_end(char **line, FILE **file);
int error_message_no_args(char *error_message);
int error_file_not_found(char *file_name);
int error_opcode_not_found(unsigned int line_number, char *non_valid_opcode,
		char **array_of_tokens);
int error_push_non_digit(unsigned int line_number);
int error_stack_empty_pint(unsigned int line_number);
int error_stack_empty_pop(unsigned int line_number);
int error_swap(unsigned int line_number);
int error_add(unsigned int line_number);
int error_opp(unsigned int line_number, char *op);
int error_divion_by_zero(unsigned int line_number);
int error_stack_out_of_range(unsigned int line_number);
int error_stack_empty_pchar(unsigned int line_number);
char *_itoa(int line_num);
int is_number(char *number);
int stack_push_handler(char **array_of_tokens, unsigned int *line_number,
		char **line, FILE **file);
int queue_push_handler(char **array_of_tokens, unsigned int *line_number,
		char **line, FILE **file);
int array_of_tokens_counter(char **array_of_tokens);
void _print_number(int line_number);
int _list_length(void);
#endif
