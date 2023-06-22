#include "monty.h"

/**
 * get_tokens - tokenizes opcodes and their values
 * @glob: list of global attributes
 * Return: pointer to tokenized array or NULL if failed
 */
char **get_tokens(globals_t *glob)
{
	char *delim = "\v\t\n ";
	char *token = NULL;
	unsigned int count = 1, i;

	glob->copy = strdup(glob->line);
	if (glob->copy == NULL)
		malloc_fail(glob->copy, glob);

	token = strtok(glob->copy, delim);
	if (token == NULL)
	{
		free_alloced(glob);
		return (NULL);
	}

	count++;
	token = strtok(NULL, delim);
	if (token != NULL)
		count++;
	glob->count = count - 1;
	glob->tokarr = malloc(sizeof(char *) * count);
	if (glob->tokarr == NULL)
		dmalloc_fail(glob->tokarr, glob);

	token = strtok(glob->line, delim);
	for (i = 0; token != NULL; i++)
	{
		glob->tokarr[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (glob->tokarr[i] == NULL)
			malloc_fail(glob->tokarr[i], glob);

		strcpy(glob->tokarr[i], token);
		token = strtok(NULL, delim);
	}
	glob->tokarr[i] = NULL;
	return (glob->tokarr);
}
