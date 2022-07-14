#define _GNU_SOURCE
#include "main.h"


void read_file(char *filename, stack_t **stack)
{
	char *line_buf = NULL;
	char *line;
	size_t line_buf_sz = 0;
	int line_count = 1;
	int read_line;
	int close_file;
	exe_cmd s;
	FILE *fp = fopen(filename, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		error_exit(stack);
	}

	while ((read_line = getline(&line_buf, &line_buf_sz, fp)) != -1)
	{
		line = convert_cmd(line_buf);
		if (line ==NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = match_cmd(line);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",line_count, line);
			error_exit(stack);
		}
		s(stack, line_count);
		line_count ++;
	}

	free(line_buf);
	close_file = fclose(fp);
	if (close_file == -1)
		exit(EXIT_FAILURE);
	
}
/**
 * convert_cmd - parses a line for an opcode and arguments
 * @line: the line to be parsed
 *
 * Return: returns the opcode or null on failure
 */
char *convert_cmd(char *cmd)
{
	char *op_code;
	op_code = strtok(cmd, "\n");
	if (op_code == NULL)
		return (NULL);
	return (op_code);
}

exe_cmd match_cmd(char* str)
{
	int i = 0;

	instruction_t op[] = INSTRUCTIONS;
	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			return (op[i].f);
		}
		i++;
	}
	return NULL;
}
