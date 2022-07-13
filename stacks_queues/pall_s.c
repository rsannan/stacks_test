#include "main.h"
#include "func.h"

void pall()
{
	stack_t *tmp = top_s;
	/* Add required error message here*/
	/*if (top == NULL)
		return NULL;*/
	while (tmp != NULL)
	{
		/*Add print func here*/
		tmp = tmp->next;
	}

	return;
}
