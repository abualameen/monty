#include "monty.h"
/**
 * push - adds mem to stack
 * @stack: rep the head of a doubly links list in resp of stack
 * @line_number: line number of opcode file
 * Return: 0
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *argu = strtok(NULL, " \n");
	int data;
	stack_t *new_node;

	/*if (argu == NULL || !is_numb(argu))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}*/
	data = atoi(argu);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
	/*printf("%d\n", new_node->n);*/
	if (argu == NULL || !is_numb(argu))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", new_node->n);
	}
}
