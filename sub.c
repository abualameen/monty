#include "monty.h"
/**
 * sub - sub two topmost val in a stack
 * @stack: stack head
 * @line_number: line number
 * Return: 0
 */


void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *latest;
	stack_t *subb;
	stack_t *save;

	subb = malloc(sizeof(stack_t));
	if (subb == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	latest = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	subb->n = (*stack)->next->n - latest->n;
	save = latest->next;
	subb->prev = NULL;
	subb->next = save->next;
	free(save);
	free(latest);
	*stack = subb;
}
