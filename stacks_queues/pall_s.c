#include "main.h"

void pall()
{
	stack_t *tmp = top;
	/* Add required error message here*/
	if (top == NULL)
		return NULL;
	while (tmp != NULL)
	{
		/*Add print func here*/
		tmp = tmp->next;
	}

	return;
}
