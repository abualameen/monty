#include "monty.h"
/**
 * pall - print opcode data
 * @stack: head of the doubling linked list as stack
 * @line_number: line number
 * Return: 0
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *latest = *stack;
	(void)line_number;

	while (latest != NULL)
	{
		printf("%d\n", latest->n);
		latest = latest->next;
	}
}
