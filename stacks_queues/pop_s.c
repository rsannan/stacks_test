#include "main.h"

void pop()
{
	stack_t *tmp = top;
	/*Add required error message*/
	if (top == NULL)
		return NULL;
	top = top->next;
	free(tmp);
	return;
}
