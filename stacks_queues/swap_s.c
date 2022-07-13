#include "main.h"
#include "func.h"

void swap()
{
	stack_t *tmp = top_s;
	stack_t *next;
	/*Add required error message here*/
	/*if (top == NULL || top->next == NULL)
		return NULL;*/
	tmp = top_s;
	next = top_s->next;
	top_s = next;
	next = tmp;

	next->prev = top_s;
	next->next = top_s->next;
	top_s->prev = NULL;
	top_s->next = next;

	return;
}
