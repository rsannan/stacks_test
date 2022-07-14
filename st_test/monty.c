#include "main.h"

int main(int ac, char **av)
{
	stack_t *top;
	top = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		error_exit(&top);
	}
	read_file(av[1], &top);
	free_dlistint(top);

	return(0);
}
