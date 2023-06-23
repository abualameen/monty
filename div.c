#include "monty.h"
/**
 * divi - div two topmost val in a stack
 * @stack: stack head
 * @line_number: line number
 * Return: 0
 */


void divi(stack_t **stack, unsigned int line_number)
{
	stack_t *latest;
	stack_t *divv;
	stack_t *save;

	divv = malloc(sizeof(stack_t));
	if (divv == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	latest = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (latest->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	divv->n = (*stack)->next->n / latest->n;
	save = latest->next;
	divv->prev = NULL;
	divv->next = save->next;
	free(save);
	free(latest);
	*stack = divv;
}
