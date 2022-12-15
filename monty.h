#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list rep of a stack
 * @n: integer
 * @prev: points to previous element
 * @next: points to next element 
 *
 * Description: doubly linked list node structure
 * for stack, queue, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 *
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variable - opcode and its function
 * @file: opcode
 * @push_arg: opcode handler
 * @buffer: pointer 
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct global_variable
{
	FILE *file;
	int push_arg;
	char *buffer;
} global_var;

extern global_var var_global;

void reader(char *filename, stack_t **top);
typedef void (*instructor)(stack_t **top, unsigned int number);
instructor get_opcode(char *str);
char *parser(char *line, stack_t **top, unsigned int number);
int isnum(char *str);
void _push(stack_t **top, unsigned int number);
void _pall(stack_t **top, unsigned int number);
void _pint(stack_t **top, unsigned int number);
void _pop(stack_t **top, unsigned int number);
void _swap(stack_t **top, unsigned int number);
void _add(stack_t **top, unsigned int number);
void _nop(stack_t **top, unsigned int number);
void free_list(stack_t *head);

#endif
