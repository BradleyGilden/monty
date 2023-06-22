#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **optokens;

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

/**
 * struct globals - stores commonly used variables in the program
 * @tokarr: points to the array of tokens stored
 * @line: stores the raw line of operation commands
 * @copy: stores a copy of the line
 * @file: file pointer to opened file
 * @count: counts the number of tokens per line
 * @l_num: stores the line number
 */
typedef struct globals
{
	char **tokarr;
	char *line;
	char *copy;
	FILE *file;
	int count;
	unsigned int l_num;
} globals_t;


void free_tokens(char **tokarr);
void free_alloced(globals_t *glob);
void malloc_fail(char *line, globals_t *glob);
void push_err(stack_t *stack, globals_t *glob);
void dmalloc_fail(char **tokarr, globals_t *glob);
void checkargs(int ac);
void checkstream(FILE *file, char *filename);


char **get_tokens(globals_t *glob);
void validate_opcode(globals_t *glob, stack_t *stack);
int _isdigit(char *str);

void (*get_ops(char *opcode))(stack_t **stack, unsigned int line_number);
void op_push(stack_t **head, unsigned int line_number);
void op_pall(stack_t **head, unsigned int line_number);
void op_pint(stack_t **head, unsigned int line_number);
void op_pop(stack_t **head, unsigned int line_number);
void op_swap(stack_t **head, unsigned int line_number);
void op_add(stack_t **head, unsigned int line_number);
void op_nop(stack_t **head, unsigned int line_number);
void op_sub(stack_t **head, unsigned int line_number);
void op_div(stack_t **head, unsigned int line_number);
void op_mul(stack_t **head, unsigned int line_number);
void op_mod(stack_t **head, unsigned int line_number);
void op_pchar(stack_t **head, unsigned int line_number);
void op_pstr(stack_t **head, unsigned int line_number);
void op_rotl(stack_t **head, unsigned int line_number);
void op_rotr(stack_t **head, unsigned int line_number);

void free_list(stack_t *head);

#endif /*_MONTY_H_*/
