#include "monty.h"
/**
 * get_func_opcode - gets the function pointer to the opcode func
 * @opcodee: the opcode
 * Return: 0
 */

void (*get_func_opcode(const char *opcodee))(stack_t **, unsigned int)
{
	instruction_t opcodes[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{NULL, NULL}
	};
	int x = 0;

	while (opcodes[x].opcode != NULL)
	{
		if (strcmp(opcodes[x].opcode, opcodee) == 0)
		{
			return (opcodes[x].f);
		}
		x++;
	}
	return (NULL);
}
