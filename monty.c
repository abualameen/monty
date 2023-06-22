#include "monty.h"
#include <stdio.h>
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
	int k, seen;
	
	instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL} 
    	};
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
		if (opcode != NULL)
		{
			seen = 0;
			for (k = 0; instructions[k].opcode != NULL; k++)
			{
				if (strcmp(opcode, instructions[k].opcode) == 0)
				{
					instructions[k].f(&stack, line_number);
					seen = 1;
					break;
				}
			}
			if (!seen)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				free(lineptr);
				fclose(file);
				return (EXIT_FAILURE);	
			}
		}
		line_number++;
	}
	fclose(file);
	free(lineptr);
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
