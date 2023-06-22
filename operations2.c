#include "monty.h"
#include <stdlib.h>

/**
 * op_pop - removes node from the top of the stack
 * @head: pointer to the top of the stack
 * @line_number: line number at which an opcode is executed
 */
void op_pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_tokens(optokens);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = (*head)->next;
	free(temp);
	if (*head != NULL)
		(*head)->prev = NULL;
}

/**
 * op_swap - swaps first two elements of the stack
 * @head: pointer to the top of the stack
 * @line_number: line number at which an opcode is executed
 */
void op_swap(stack_t **head, unsigned int line_number)
{
	stack_t *second_node = NULL;
	stack_t *third_node = NULL;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(optokens);
		exit(EXIT_FAILURE);
	}

	second_node = (*head)->next;
	if (second_node->next != NULL)
		third_node = second_node->next;
	second_node->next = *head;
	second_node->prev = NULL;
	(*head)->next = third_node;
	(*head)->prev = second_node;
	if (third_node != NULL)
		third_node->prev = *head;
	*head = second_node;

}

/**
 * op_add - adds top two elements of the stack, stores the result in the...
 *          second elements and pops the first element
 * @head: pointer to the top of the stack
 * @line_number: line number at which an opcode is executed
 */
void op_add(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_tokens(optokens);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n = (*head)->n + (*head)->next->n;
	op_pop(head, line_number);
}

/**
 * op_nop - does nothing
 * @head: pointer to the top of the stack
 * @line_number: line number at which an opcode is executed
 */
void op_nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * op_sub - subtracts the top two elements of the stack, stores the result in
 *          the second element and pops the first element
 * @head: pointer to the top of the stack
 * @line_number: line number at which an opcode is executed
 */
void op_sub(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_tokens(optokens);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n =  (*head)->next->n - (*head)->n;
	op_pop(head, line_number);
}
