#include "main.h"

/**
 * error_exit - frees the stack and exits due to erro
 * @stack: pointer to the head of the stack
 *
 */
void error_exit(stack_t **stack)
{
	if (*stack)
		free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
 * _atoi - convert a string to an integer.
 * @s: the string to be comverted.
 *
 *Return: The integer value of the comverted string.
 */

int _atoi(char *s)
{
	if (*s < '0' && *s > '9')
	{
		int sign = 1;
		unsigned int num = 0;

		do {

			if (*s == '-')
				sign *= -1;

			else if (*s >= '0' && *s <= '9')
				num = (num * 10) + (*s - '0');

			else if (num > 0)
				break;
		} while (*s++);

		return (num * sign);
	}
	return (-1);
}

/**
 * add_dnodeint - add node to the beginning of list
* @head: pointer to first node
* @n: data inside node
* Return: pointer to first node
*/
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	if (*head == NULL)
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (*head);
	}

	(*head)->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}

/**
 * free_dlistint - free a list
 * @head: pointer to first node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
