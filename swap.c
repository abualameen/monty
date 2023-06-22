#include "monty.h"
/**
 * swap - swap two top member
 * @stack: rep the head
 * @line_number: the number of lines
 * Return: 0
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *latest;
	stack_t *save;

	latest = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	save = latest->next;
	latest->prev = save;
	latest->next = save->next;
	if (save->next != NULL)
	{
		save->next->prev = latest;
	}
	save->prev = NULL;
	save->next = latest;
	*stack = save;
}
