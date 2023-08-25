#include "monty.h"

/**
 * trim_text - remove whitespaces
 * @text: input instruction
 * Return: trimmed text
 */

char *trim_text(char *text)
{
	size_t i = 0;

	while (i < strlen(text))
	{
		if (text[i] == '\t')
			text[i] = ' ';
		i++;
	}
	return (text);
}

/**
 * check_argument - convert argument into digits
 * @numcode: argument digits
 * @argument: argument number
 * Return: if it failed or not
 */

int check_argument(int *numcode, char *argument)
{
	int i = 0;
	int operator = 1;
	int found = 0;

	if (argument == NULL || argument[0] == '\n')
		return (-1);

	while (argument[i] != '\0' && argument[i] != '\n')
	{
		if (!(argument[i] >= '0' && argument[i] <= '9'))
		{
			if (operator == 1 && argument[i] == '-' && found == 0)
				operator = -1;
			else
				return (-1);
		}
		else
			found = 1;
		i++;
	}

	*numcode = atoi(argument);
	return (0);
}

/**
 * processInstruction - chooses which function the line needs
 * @i: line number
 * @p: line from file
 * @top: the top of the stack
 * @mode: stack or queue mode
 */
void processInstruction(int i, stack_t **top, char *p, int *mode)
{
	char *trimmed_p = trim_text(p);
	char *instruction = strtok(trimmed_p, " ");
	char *argument = strtok(NULL, " ");
	char *clear_ins = strtok(instruction, "\n");
	int numcode;
	int status = check_argument(&numcode, argument);

	if (clear_ins == NULL)
		return;

	if (strcmp(clear_ins, "push") == 0)
	{
		if (status == -1)
		{
			fprintf(stderr, "L%i: usage: push integer\n", i);
			exit(EXIT_FAILURE);
		}
		else
			push(top, numcode, mode);
	}
	else if (strcmp(clear_ins, "stack") == 0)
		*mode = 0;
	else if (instructions(i, top, clear_ins) == 1)
		return;
	else if (strcmp(clear_ins, "queue") == 0)
		*mode = 1;
	else
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", i, instruction);
		exit(EXIT_FAILURE);
	}
}



/**
 * allocateStack - ...
 * Return: new stack
 */
stack_t *allocateStack()
{
	stack_t *newStackMember = malloc(sizeof(stack_t));

	if (newStackMember == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newStackMember->next = NULL;
	newStackMember->prev = NULL;
	return (newStackMember);
}
