#define _GNU_SOURCE
#include<stdio.h>
#include "monty.h"

diff_t diff;

/**
 * read_file - reads a bytecode file and runs commands
 * @fileptr: pathname to file
 * @stack: pointer to the top of the stack
 */
void read_file(char *fileptr, stack_t **stack)
{
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func s;
	int check, get;

	diff.f = fopen(fileptr, "r");

	if (diff.f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileptr);
		exit(EXIT_FAILURE);
	}

	while ((get = getline(&diff.buffer, &i, diff.f)) != -1)
	{
		line = parse_line(diff.buffer, stack, line_count);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = op_func_obt(line);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}
		s(stack, line_count);
		line_count++;
	}
	free(diff.buffer);
	check = fclose(diff.f);
	if (check == -1)
		exit(-1);
}

/**
 * op_func_obt -  checks opcode and returns the correct function
 * @s: the opcode
 * Return: returns a functions, or NULL on failure
 */
instruct_func op_func_obt(char *s)
{
	int i;

	instruction_t instruct[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"pop", stack_pop},
		{"swap", stack_swap},
		{"add", stack_add},
		{"nop", stack_nop},
		{"sub", stack_sub},
		{"mul", stack_mul},
		{"div", stack_div},
		{"mod", stack_mod},
		{"pchar", stack_pchar},
		{"pstr", stack_pstr},
		{"rotl", stack_rotl},
		{"rotr", stack_rotr},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, s) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

/**
 * isnumber - checks if a string is a number
 * @s: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *s)
{
	unsigned int i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 * @stack: pointer to the head of the stack
 * @line_num: the current line number
 * Return: returns the opcode or null on failure
 */
char *parse_line(char *line, stack_t **stack, unsigned int line_num)
{
	char *op_code, *push, *arg;
	(void)stack;

	push = "push";
	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnumber(arg) == 1 && arg != NULL)
		{
			diff.arg_stack = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}
