#include "monty.h"

/**
 * main - drives Monty program
 * @argc: argument count
 * @argv: argument pointer
 * Return: EXIT_SUCCESS on success, else EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	stack_t *stack;

	stack = NULL;
	/*if lack of filename */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	reader(argv[1], &stack);
	free_list(stack);

	return (0);
}

