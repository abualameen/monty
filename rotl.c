#include "monty.h"
/**
 * rotl - 'prints char at top of the stack\n'
 * @stack: stack head
 * @line_number: line number
 * Return: 0
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *latest;
	stack_t *head;
	stack_t *last;
	stack_t *save1;
	int counter = 0;
	(void)line_number;

	latest = *stack;
	head = *stack;
	if (*stack != NULL)
	{
		save1 = (*stack)->next;
	}
	if (latest != NULL)
	{
		while (latest->next != NULL)
		{
			counter++;
			last = latest->next;
			latest = latest->next;
		}
		head->next = NULL;
		head->prev = last;
		last->next = head;
		head = last;
		save1->prev = NULL;
		*stack = save1;
	}
}
