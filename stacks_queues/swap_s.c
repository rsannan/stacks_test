#include "main.h"

void swap()
{
	stack_t *tmp = top;
	stack_t *next;
	/*Add required error message here*/
	if (top == NULL || top->next == NULL)
		return NULL;
	tmp = top;
	next = top->next;
	top = next;
	next = tmp;

	next->prev = top;
	next->next = top->next;
	top->prev = NULL;
	top->next = next;

	return;
}
