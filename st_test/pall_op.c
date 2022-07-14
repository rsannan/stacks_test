#include "main.h"

void fpall(stack_t **stack,__attribute__ ((unused))unsigned int line_number)
{
	stack_t *tmp = *stack;

	
	while (tmp != NULL)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
	return;
}
