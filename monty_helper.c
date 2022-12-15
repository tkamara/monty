#include "monty.h"

/**
 * reader - reads the bytecode file
 * @filename: name of file
 * @top: pointer to head of stack
 *
 * Return: none
 */

void reader(char *filename, stack_t **top)
{
	char *line;
	int line_counter = 1;
	int checker;
	int read;
	size_t i = 0;
	instructor s;

	var_global.file = fopen(filename, "r");
	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while((read = getline(&var_global.buffer, &i, var_global.file)) != -1)
	{
		line = parser(var_global.buffer, top, line_counter);
		if (line == NULL || line[0] == '#')
		{
			line_counter++;
			continue;
		}
		s = get_opcode(line);
		if (s = NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, line);
			exit(EXIT_FAILURE);
		}
		s(top, line_counter);
		line_counter++;
	}
	free(var_global.buffer);
	checker = fclose(var_global.file);
	if (check == -1)
	{
		exit(-1);
	}
}

/**
 * @get_opcode - checks the opcode
 * @str: the opcode
 *
 * Return: the function
 */

instructor get_opcode(char *str)
{
	int j;

	instruction_t inst[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL},
	};

	j = 0;
	while(inst[j].f != NULL && strcmp(inst[j].opcode, str) != 0)
	{
		j++;
	}

	return (inst[j].f);
}

/**
 * parser - parses line for opcode
 * @line: line to be parsed
 * @top: pointer to head of stack
 * @number: the current line number
 *
 * Return: the opcode
 */

char *parser(char *line, stack_t **top, unsigned_int number)
{
	char *code, *arg, *push;
	(void)top;

	push = "push";
	code = strtok(line, "\n ");
	if (code == NULL)
	{
		return (NULL);
	}

	if (strcmp(code, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnum(arg) == 1 && arg != NULL)
		{
			var_global.push_arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", number);
			exit(EXIT_FAILURE);
		}
	}

	return (code);
}

/**
 * isnum - check whether string is a num
 * @str: the string
 *
 * Return: 1 if num
 */

int isnum(char *str)
{
	unsigned int k;

	if (str == NULL)
	{
		return (0);
	}

	k = 0;
	while (str[k])
	{
		if (str[0] == '-')
		{
			k++;
			continue;
		}
		if (!isdigit(str[k]))
		{
			return (0);
		}
		k++;
	}
	return (1);
}
