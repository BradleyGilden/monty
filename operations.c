#include "monty.h"

/**
 * get_ops - the function returns a specific op_func depending on opcode called
 * @opcode: opcode that was tokenized
 * Return: NULL if failed or the pointer to the opfunc
 */
void (*get_ops(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t functions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{NULL, NULL}
	};

	for (i = 0; functions[i].opcode; i++)
	{
		if (strcmp(opcode, functions[i].opcode) == 0)
			return (functions[i].f);
	}
	return (NULL);
}

/**
 * op_push - the function returns a specific op_func depending on opcode called
 * @head: pointer to the top of the stack
 * @line_number: line number at which an opcode is executed
 */
void op_push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int n;
	(void)line_number;

	if (new_node == NULL)
	{
		free_tokens(optokens);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	n = atoi(optokens[1]);
	new_node->n = n;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
	}
	*head = new_node;
}

/**
 * free_list - this function free's the stack
 * @head: pointer to the top of the stack
 */
void free_list(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * op_pall - displays all elements in the stack
 * @head: pointer to the top of the stack
 * @line_number: line number at which an opcode is executed
 */
void op_pall(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = *head;
	(void)line_number;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * op_pint - prints node at the top of the stack
 * @head: pointer to the top of the stack
 * @line_number: line number at which an opcode is executed
 */
void op_pint(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_tokens(optokens);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
