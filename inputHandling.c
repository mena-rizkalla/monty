#include "monty.h"

/**
 * instructions - ...
 * @i: ...
 * @top: ...
 * @clear_ins: ...
 * Return: 1 if used, else 0
 */

int instructions(int i, stack_t **top, char *clear_ins)
{
	if (strcmp(clear_ins, "pall") == 0)
	{
		pall(top);
		return (1);
	}
	else if (strcmp(clear_ins, "pint") == 0)
	{
		pint(top, i);
		return (1);
	}
	else if (strcmp(clear_ins, "pop") == 0)
	{
		pop(top, i);
		return (1);
	}
	else if (strcmp(clear_ins, "swap") == 0)
	{
		swap(top, i);
		return (1);
	}
	return (0);
}
