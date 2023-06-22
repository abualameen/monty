#include "monty.h"
int if_valid_int(const char *arg);
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
	
	if (argu == NULL || !if_valid_int(argu))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	data = atoi(argu);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		new_node->n = data;
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->n = data;
		new_node->next = *stack;
		new_node->prev = NULL;
		if (*stack != NULL)
		{
			(*stack)->prev = new_node;
			*stack = new_node;
		}
	}
}

/**
 * if_valid_int - checks for valid int
 * @arg: argument to check
 * Return: 0
 */
int if_valid_int(const char *arg)
{
	if (*arg == '-' || *arg == '+')
	{
		arg++;
	}
	while (*arg)
	{
		if (!isdigit(*arg))
		{
			return (0);
		}
		arg++;
	}
	return (1);
}

