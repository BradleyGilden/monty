#include "monty.h"

/**
 * free_tokens - free's all tokens in optokens
 * @tokarr: token array
*/
void free_tokens(char **tokarr)
{
	int i = 0, len = 0;

	if (tokarr == NULL || *tokarr == NULL)
		return;

	while (tokarr[i++])
	{
		len++;
	}

	for (i = len - 1; i >= 0; i--)
		free(tokarr[i]);

	free(tokarr);
}

/**
 * free_alloced - free's necessary global variables
 * @glob: list of globals
*/
void free_alloced(globals_t *glob)
{
	if (glob->line != NULL)
		free(glob->line);
	if (glob->tokarr != NULL)
		free_tokens(glob->tokarr);
	if (glob->copy != NULL)
		free(glob->copy);
	glob->line = NULL, glob->copy = NULL, glob->tokarr = NULL;
}
