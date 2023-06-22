#include "monty.h"
stack_t *stack = NULL;
int supress(void);
/**
 * main - entry point of function
 * @argc: argu count
 * @argv: argu vector
 * Return: 0
 */

int main(int argc,  char *argv[])
{
	const char *file_name;
	FILE *file;
	char *lineptr = NULL;
	size_t size_lineptr = 0;
	unsigned int line_number = 1;
	char *opcode;

	file_name = argv[1];
	file = fopen(file_name, "r");
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		return (EXIT_FAILURE);
	}
	while (getline(&lineptr, &size_lineptr, file) != -1)
	{
		opcode = strtok(lineptr, " \t\n");
		if (opcode != NULL && opcode[0] != '#')
		{
			void (*func_opcode)(stack_t **, unsigned int) = get_func_opcode(opcode);

			if (func_opcode == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				fclose(file);
				free(lineptr);
				free(stack);
				return (EXIT_FAILURE);
			}
			else
			{
				func_opcode(&stack, line_number);
			}
		}
		line_number++;
	}
	fclose(file);
	free(lineptr);
	free(stack);
	return (EXIT_SUCCESS);
}
/**
 * supress - supreses
 * Return: 0
 */

int supress(void)
{
	return (0);
}
