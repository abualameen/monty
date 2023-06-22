#include "monty.h"
/**
 * free_stack - free stack
 * @stack: stack
 * Return: 0
 */

void free_stack(stack_t **stack)
{
	stack_t *latest;
	stack_t *wait;

	latest = *stack;

	if (*stack == NULL)
	{
		return;
	}
	while (latest != NULL)
	{
		wait = latest->next;
		free(latest);
		latest = wait;
	}
}
