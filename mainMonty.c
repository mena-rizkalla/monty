#define  _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>

/**
 * main - handles the file
 * opens the file specified in argv[1]
 * @argc: number of args, always 2
 * @argv: the args
 * Return: exit code
 */



int main(int argc, char *argv[])
{
	FILE *fileptr;
	stack_t *stack = NULL;
	char *buffer = NULL;
	size_t bufferSize = 0;
	int i = 1;
	int mode = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fileptr = fopen(argv[1], "r");

	if (fileptr == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer, &bufferSize, fileptr) != -1)
	{
		processInstruction(i, &stack, buffer, &mode);
		freeCharPointer(&buffer);
		i++;
	}
	freeCharPointer(&buffer);
	fclose(fileptr);
	freeStack(&stack);

	return (0);
}
