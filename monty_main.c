#include "monty.h"

char **optokens = NULL;

/**
 * main - Entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: 0 always
 */

int main(int argc, char *argv[])
{
	globals_t glob = {NULL, NULL, NULL, NULL, 0, 0};
	stack_t *stack = NULL;
	void (*functions)(stack_t **, unsigned int);
	char *filename;
	size_t n = 0;
	ssize_t ret = 0;

	checkargs(argc);
	filename = argv[1];
	glob.file = fopen(filename, "r");
	checkstream(glob.file, filename);

	while ((ret = getline(&(glob.line), &n, glob.file)) >= 0)
	{
		glob.l_num += 1;
		if (ret == 0)
			continue;
		optokens = get_tokens(&glob);
		if (optokens == NULL)
			continue;
		validate_opcode(&glob, stack);
		functions = get_ops(optokens[0]);
		if (functions == NULL)
			continue;
		functions(&stack, glob.l_num);
		free_alloced(&glob);
	}
	if (glob.line != NULL)
		free(glob.line);
	if (stack != NULL)
		free_list(stack);
	fclose(glob.file);
	return (0);
}
