#include "monty.h"
/**
 * pstr - 'prints char at top of the stack\n'
 * @stack: stack head
 * @line_number: line number
 * Return: 0
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *latest;
	(void)line_number;

	latest = *stack;
	if (*stack == NULL)
	{
		printf("\n");
	}
	while (latest != NULL)
	{
		if ((latest->n >= 65 && latest->n <= 90) ||
			(latest->n >= 97 && latest->n <= 122))
		{
			if (latest->n == 0)
			{
				break;
			}
			printf("%c", latest->n);
			latest = latest->next;
		}
		else
		{
			break;
		}
	}
	printf("\n");
}
