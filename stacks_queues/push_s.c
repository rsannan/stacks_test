#include "main.h"
#include "func.h"

void push(int n)
{
	stack_t *newnode = (stack_t*)malloc(sizeof(stack_t));
	/*replace error message with required one*/
	/*if (newnode == NULL)
		return NULL;*/
	if (top_s != NULL)
		top_s->prev = newnode;
	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = top_s;
	top_s = newnode;

	return;
}
