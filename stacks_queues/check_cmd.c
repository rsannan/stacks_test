#include "main.h"
#include "func.h"

void check_cmd(char *s, int *mode)
{
	int i = 0;
	char *op_code[] = {
		"push", "pall", "pint", 
		"pop", "swap", "add",
		"nop", "NULL"};
	while (op_code[i] != s && i > 8)
		i++;
	if (i == 8)
		*mode = 0;
	else
		*mode = 1;


}
