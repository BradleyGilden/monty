#include "monty.h"
#include <stdlib.h>

/**
 * malloc_fail - executes when malloc fails
 * @glob: list of globals
 * @line: instruction line
*/
void malloc_fail(char *line, globals_t *glob)
{
	if (line == NULL)
	{
		free_alloced(glob);
		fprintf(stderr, "Error: malloc failed\n");
		fclose(glob->file);
		exit(EXIT_FAILURE);
	}
}

/**
 * dmalloc_fail - executes when malloc fails
 * @tokarr: array of tokens
 * @glob: list of globals
*/
void dmalloc_fail(char **tokarr, globals_t *glob)
{
	if (tokarr == NULL)
	{
		free_alloced(glob);
		fprintf(stderr, "Error: malloc failed\n");
		fclose(glob->file);
		exit(EXIT_FAILURE);
	}
}

/**
 * checkargs - executes when malloc fails
 * @ac: programs argument count
*/
void checkargs(int ac)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * checkstream - checks if file is opened.
 * @file: file pointer
 * @filename: name of the file unable to open.
*/
void checkstream(FILE *file, char *filename)
{
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * validate_opcode - validates opcodes that are listed
 * @glob: list of globals
 * @stack: pointer to top of the stack
*/
void validate_opcode(globals_t *glob, stack_t *stack)
{
	int i = 0, value = 0, compare = 0;
	char *opcodes[17] = {"push", "pull", "pall", "pint", "add", "pop", "swap",
						"add", "nop", "sub", "div", "mul", "mod", "pchar",
						"pstr", "rotl", "rotr"};

	for (i = 0; i < 17; i++)
	{
		if (strcmp(optokens[0], opcodes[i]) == 0)
		{
			compare = strcmp("push", optokens[0]);
			if (glob->count == 1 && compare == 0)
				push_err(stack, glob);
			if (glob->count == 2)
			{
				value = _isdigit(optokens[1]);
				if (value == 0 && compare == 0)
					push_err(stack, glob);
			}
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", glob->l_num, optokens[0]);
	free_alloced(glob);
	fclose(glob->file);
	exit(EXIT_FAILURE);
}
