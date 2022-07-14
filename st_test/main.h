#ifndef MAIN_h
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#define INSTRUCTIONS               \
	{                           \
		{"push", fpush},       \
		    {"pall", fpall},   \
		{			\
			NULL, NULL      \
		}                     \
	}

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*exe_cmd)(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);
void error_exit(stack_t **stack);
exe_cmd match_cmd(char *str);
void read_file(char *filename, stack_t **stack);
char *convert_cmd(char *cmd);
int _atoi(char *s);
void fpush(stack_t **stack, unsigned int line_number);
void fpall(stack_t **stack, unsigned int line_number);

#endif
