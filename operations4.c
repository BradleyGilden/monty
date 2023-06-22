#include "monty.h"

/**
 * op_rotl - places top element of stack to the bottom
 * @head: pointer to the top of the stack
 * @line_number: line number at which an opcode is executed
 */
void op_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *end = NULL, *second = NULL;
	(void)line_number;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	end = *head;
	second = (*head)->next;

	while (end->next != NULL)
		end = end->next;

	end->next = *head;
	(*head)->prev = end;
	(*head)->next = NULL;

	second->prev = NULL;
	*head = second;
}

/**
 * op_rotr - swaps top and last element of the stack
 * @head: pointer to the top of the stack
 * @line_number: line number at which an opcode is executed
 */
void op_rotr(stack_t **head, unsigned int line_number)
{
	stack_t *end = NULL, *second = NULL, *second_l = NULL;
	int len = 0;
	(void)line_number;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	end = *head;
	second = (*head)->next;

	while (end->next != NULL)
	{
		len++;
		end = end->next;
	}
	len++;

	if (len == 2)
	{
		op_swap(head, 0);
		return;
	}
	second_l = end->prev;
	second_l->next = *head;
	(*head)->prev = second_l;
	(*head)->next = NULL;
	end->next = second;
	end->prev = NULL;
	second->prev = end;
	*head = end;
}
