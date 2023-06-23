#include "monty.h"
/**
 * mul - mul two topmost val in a stack
 * @stack: stack head
 * @line_number: line number
 * Return: 0
 */


void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *latest;
	stack_t *mull;
	stack_t *save;

	mull = malloc(sizeof(stack_t));
	if (mull == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	latest = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mull->n = (*stack)->next->n * latest->n;
	save = latest->next;
	mull->prev = NULL;
	mull->next = save->next;
	free(save);
	free(latest);
	*stack = mull;
}


