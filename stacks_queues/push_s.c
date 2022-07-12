#include "main.h"

void push(int n)
{
	stack_t *newnode = (stack_t*)malloc(sizeof(stack_t));
	/*replace error message with required one*/
	if (newnode == NULL)
		return NULL;
	if (top != NULL)
		top->prev = newnode;
	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = top;
	top = newnode;

	return;
}
