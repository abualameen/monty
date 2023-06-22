#include "monty.h"
/**
 * pint - print val at top of the stack
 * @stack: stack
 * @line_number: line number
 * Return: 0
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *latest;

	latest = *stack;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (latest == NULL)
	{
		fprintf(stderr, "L%d: can't pint, lates is empty\n", line_number);
	}
	printf("%d\n", latest->n);
}
