#include "monty.h"
/**
 * pop - print val at top of the stack
 * @stack: stack
 * @line_number: line number
 * Return: 0
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *latest;
	stack_t *save;

	latest = *stack;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (latest == NULL)
	{
		fprintf(stderr, "L%d: can't pop, lates is empty\n", line_number);
	}
	save = latest->next;
	free(latest);
	latest = save;
}
