#include "monty.h"

/**
 * op_div - divides the top two elements of the stack, stores the result in
 *          the second element and pops the first element
 * @head: pointer to the top of the stack
 * @line_number: line number at which an opcode is executed
 */
void op_div(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_tokens(optokens);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_tokens(optokens);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n =  (*head)->next->n / (*head)->n;
	op_pop(head, line_number);
}

/**
 * op_mul - multiplies the top two elements of the stack, stores the result in
 *          the second element and pops the first element
 * @head: pointer to the top of the stack
 * @line_number: line number at which an opcode is executed
 */
void op_mul(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_tokens(optokens);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n =  (*head)->next->n * (*head)->n;
	op_pop(head, line_number);
}

/**
 * op_mod - modulus the top two elements of the stack, stores the result in
 *          the second element and pops the first element
 * @head: pointer to the top of the stack
 * @line_number: line number at which an opcode is executed
 */
void op_mod(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_tokens(optokens);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_tokens(optokens);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n =  (*head)->next->n % (*head)->n;
	op_pop(head, line_number);
}

/**
 * op_pchar - displays opcode value as ascii character
 * @head: pointer to the top of the stack
 * @line_number: line number at which an opcode is executed
 */
void op_pchar(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_tokens(optokens);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_tokens(optokens);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*head)->n);
}

/**
 * op_pstr - displays opcode value as ascii character string
 * @head: pointer to the top of the stack
 * @line_number: line number at which an opcode is executed
 */
void op_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;

	if (head == NULL || *head == NULL)
	{
		return;
	}

	ptr = *head;

	while (ptr->next != NULL)
		ptr = ptr->next;
	while (ptr != NULL)
	{
		if ((ptr->n > 0 || ptr->n < 127) && ptr->n != 0)
		{
			printf("%c", ptr->n);
			ptr = ptr->prev;
		}
		else
			break;
	}
	printf("\n");
}
