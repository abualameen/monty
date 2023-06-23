#include "monty.h"
/**
 * mod - mod two topmost val in a stack
 * @stack: stack head
 * @line_number: line number
 * Return: 0
 */


void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *latest;
	stack_t *modd;
	stack_t *save;

	modd = malloc(sizeof(stack_t));
	if (modd == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	latest = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (latest->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	modd->n = (*stack)->next->n % latest->n;
	save = latest->next;
	modd->prev = NULL;
	modd->next = save->next;
	free(save);
	free(latest);
	*stack = modd;
}
