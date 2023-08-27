#include "monty.h"

/**
 * sub - subtracts
 * @top: ...
 * @i: ...
 */

void sub(stack_t **top, int i)
{
	if (top == NULL || *top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	(*top)->prev->n = (*top)->prev->n - (*top)->n;

	pop(top, i);
}

/**
 * divide - ..
 * @top: ...
 * @i: ...
 */

void divide(stack_t **top, int i)
{
	if (top == NULL || *top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", i);
		exit(EXIT_FAILURE);
	}

	(*top)->prev->n = (*top)->prev->n / (*top)->n;

	pop(top, i);
}

/**
 * mul - ..
 * @tp: ..
 * @i: ..
 */

void mul(stack_t **tp, int i)
{
	if (tp == NULL || *tp == NULL || (*tp)->prev == NULL)
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	(*tp)->prev->n = (*tp)->prev->n * (*tp)->n;

	pop(tp, i);
}


/**
 * mod - ...
 * @top: ...
 * @i: ...
 */

void mod(stack_t **top, int i)
{
	if (top == NULL || *top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", i);
		exit(EXIT_FAILURE);
	}

	(*top)->prev->n = (*top)->prev->n % (*top)->n;

	pop(top, i);
}



/**
 * rotr - rotate stack to the right
 *
 * Description: 'Function'
 *
 * @top: top node of the stack
 *
 * Return: void.
 */


void rotr(stack_t **top)
{
	stack_t *curr = *top;
	stack_t *temp = *top;

	if (curr == NULL || curr->prev == NULL)
		return;

	if (curr->prev->prev == NULL)
	{
		swap(top, 0);
		return;
	}

	while (curr->prev != NULL)
	{
		curr = curr->prev;
	}

	temp = curr->next;
	temp->prev = NULL;
	curr->prev = (*top);
	curr->next = NULL;
	(*top)->next = curr;

	(*top) = curr;
}
