#include "main.h"

void add()
{
	stack_t *tmp = top;
	/*Add required error message*/
	if (top == NULL|| top->next == NULL)
		return NULL;

	top = top->next;
	top->n = tmp->n + top->n;
	top->prev = NULL;
	free(tmp);

	return;
}
