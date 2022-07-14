#include "main.h"

void fpush(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = (stack_t*)malloc(sizeof(stack_t));
	char *arg;
	int num_arg = 0;
	if(newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error_exit(stack);
	}

	arg = strtok(NULL, "\n");
	num_arg = atoi(arg);
	if(num_arg == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		error_exit(stack);
	}

	add_dnodeint(stack, num_arg);

	return;
}
