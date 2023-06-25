#include "monty.h"

/**
 * stack_pchar - prints the ASCII value of char at the top of the stack.
 * @stack: pointer to the top of the stack
 * @line_num: the index of the current line
 */
void stack_pchar(stack_t **stack, unsigned int line_num)
{
	int val;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		free(diff.buffer);
		fclose(diff.f);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;
	if (val > 127 || val < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		free(diff.buffer);
		fclose(diff.f);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(val);
	putchar('\n');
}

/**
 * _isalpha - checks if int is in alphabet
 * @s: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int s)
{
	if ((s >= 97 && s <= 122) || (s >= 65 && s <= 90))
		return (1);
	else
		return (0);
}

/**
 * _pstr - prints the string 9f top of stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void stack_pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	int s = 0;

	(void)line_num;


	while (tmp)
	{
		s = tmp->n;
		if (s == 0 || _isalpha(s) == 0)
			break;
		putchar(s);
		tmp = tmp->next;
	}
	putchar('\n');
}
