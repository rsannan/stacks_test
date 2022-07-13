#include "main.h"
#include "func.h"
line_buff = NULL;
top_s = NULL;
void convert_cmd()
{
	int i = 0;
	int mode = 0;
	char *s;
	char op[] = "push";
	s = strtok(line_buff, " ");
	while (s != NULL)
	{
		check_cmd(s, &mode);
		if (mode == 1 || local_argv[0] == op)
		{
			local_argv[i] = s;
			i++;
		}
		s = strtok(NULL, " ");
	}
}
int exe_cmd()
{
	int j = 0;
	instruction_t op[] ={
		{"push",push}, {"pall", pall},
		{"pint", pint}, {"pop",pop},
		{"swap", swap}, {"add", add},
		{"nop",nop}, {"NULL", NULL}
	};

	while (op[j].opcode != NULL)
	{
		if(op[j].opcode == local_argv[0])
		{
			if (local_argv[0] == op[0].opcode)
				op[j].f(local_argv[1]);
			else
				op[j].f();
		}
		j++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	/*required error mesasage*/
	size_t line_buf_sz = 0;
	int line_count = 0;
	ssize_t line_size;
	FILE *fp = fopen(argv[1], "r");
	top = NULL;
	/*required error mesasage*/
	if (argc > 2)
		return (1);
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	line_size = getline(&line_buff, &line_buf_sz, fp);
	while (line_size >= 0)
	{
		line_count++;
		if ((line_size > 0) && (line_buff[line_size - 1] == '\n'))
			line_buff[line_size - 1] = '\0';

		convert_cmd();
		exe_cmd();
		line_size = getline(&line_buff, &line_buf_sz, fp);
	}

	return (1);



}
