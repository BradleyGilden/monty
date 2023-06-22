#include "monty.h"

/**
 * _isdigit - checks if string contains only digits
 * @str: input string
 *
 * Return: 1 if it is a digit
 *         0 if not
*/

int _isdigit(char *str)
{
	unsigned int i = 0;

	if (str == NULL)
		return (1);

	if (str[0] == '-' && str[1] != '\0')
		i++;

	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}

	return (1);
}

/**
 * push_err - stderr output for push command error
 * @stack: pointer to front of stack
 * @glob: list of globals
*/
void push_err(stack_t *stack, globals_t *glob)
{
	fprintf(stderr, "L%d: usage: push integer\n", glob->l_num);
	free_list(stack);
	free_alloced(glob);
	fclose(glob->file);
	exit(EXIT_FAILURE);
}
