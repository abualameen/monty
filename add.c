#include "monty.h"
/**
 * add - add two topmost val in a stack
 * @stack: stack head
 * @line_number: line number
 * Return: 0
 */


void add(stack_t **stack, unsigned int line_number)
{
	stack_t *latest;
	stack_t *addd;
	stack_t *save;

	addd = malloc(sizeof(stack_t));
	if (addd == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	latest = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	addd->n = latest->n + (*stack)->next->n;
	save = latest->next;
	addd->prev = NULL;
	addd->next = save->next;
	free(save);
	free(latest);
	*stack = addd;
}
