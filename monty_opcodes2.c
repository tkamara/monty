#include "monty.h"

/**
 * _add - add top two elements of stack
 * @top: head of stack
 * @number: line number for current line of code
 *
 * Return: none
 */

void _add(stack_t **top, unsigned int number)
{
	stack_t *hold;

	int i = 0, sum = 0;
	*hold = *top;
	if (hold == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	while (hold)
	{
		hold = hold->next;
		i++;
	}

	if (top == NULL || (*top)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	sum = (*top)->next->n + (*top)->n;
	_pop(top, number);
	(*top)->n = sum;
}

/**
 * _nop - no action
 * @top: head of stack
 * @number: line number for current line of code
 *
 * Return: none
 */

void _nop(__attribute__ ((unused))stack_t **top, __attribute__ ((unused))unsigned int number)
{
	;
}

/**
 * free_list - free the linked list
 * @head: pointer to node
 *
 * Return: none
 */

void free_list(stack_t *head)
{
	stack_t *hold;

	while (head != NULL)
	{
		hold = head->next;
		free(head);
		head = hold;
	}
}
