#include "monty.h"
/**
 * is_number - xhecks if a str is a num.
 * @str: str to check
 * Return: 1 if ...
 */
int is_numb(char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
	{
		return 0;
	}
	if (str[0] == '-')
	{
		i++;
	}
	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
	    	{
			return 0;
		}
	}
	return 1;
}
