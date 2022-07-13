#include "main.h"
#include "func.h"

void pop()
{
	stack_t *tmp = top_s;
	/*Add required error message*/
	/*if (top == NULL)
		return NULL;*/
	top_s = top_s->next;
	free(tmp);
	return;
}
