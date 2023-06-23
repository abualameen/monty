#include "monty.h"
/**
 * pchar - 'prints char at top of the stack\n'
 * @stack: stack head
 * @line_number: line number
 * Return: 0
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *latest;

	latest = *stack;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((latest->n >= 65 && latest->n <= 90) ||
		(latest->n >= 97 && latest->n <= 122))
	{
		printf("%c\n", latest->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
