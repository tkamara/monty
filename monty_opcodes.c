#include "monty.h"

/**
 * _push - pushes element to stack
 * @top: head of stack
 * @number: line number for current line of code
 *
 * Return: none
 */

void _push(stack_t **top, __attribute__ ((unused))unsigned int number)
{
	stack_t *new;
	(void)number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new->n = var_global.push_arg;
	new->next = *top;
	new->prev = NULL;
	if (*top != NULL)
		(*top)->prev = new;
	*top = new;
}

/**
 * _pall - print all values on stack
 * @top: head of stack
 * @number: line number for the current line of code
 *
 * Return: none
 */

void _pall(stack_t **top, __attribute__ ((unused))unsigned int number)
{
	stack_t *step;

	step = *top;
	while (step != NULL)
	{
		printf("%d\n", step->n);
		step = step->next;
	}
}

/**
 * _pint - print value at top of stack
 * @top: head of stack
 * @number: line number for the current line of code
 *
 * Return: none
 */

void _pint(stack_t **top, unsigned int number)
{
	stack_t *step;

	if (step == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", step->n);
}

/**
 * _pop - remove top element of stack
 * @top: head of stack
 * @number: line number for the current line of code
 *
 * Return: void
 */

void _pop(stack_t **top, unsigned int number)
{
	stack_t *remove = *top;

	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack \n", number);
		exit(EXIT_FAILURE);
	}
	*top = remove->next;
	if (*top != NULL)
	{
		(*top)->prev = NULL;
	}
	free(remove)
}

/**
 * _swap - swap top two elements of stack
 * @top: head of stack
 * @number: line number for the current line of code
 *
 * Return: none
 */

void _swap(stack_t **top, unsigned int number)
{
	stack_t *step;
	int i;

	step = *top;
	if (step == NULL || step->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	i = step->n;
	step->n = step->next->n;
	step->next->n = i;
}




