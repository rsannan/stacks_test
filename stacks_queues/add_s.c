#include "main.h"
#include "func.h"

void add()
{
	stack_t *tmp = top_s;
	/*Add required error message*/
	/*if (top == NULL|| top->next == NULL)
		return NULL;*/

	top_s = top_s->next;
	top_s->n = tmp->n + top_s->n;
	top_s->prev = NULL;
	free(tmp);

	return;
}
