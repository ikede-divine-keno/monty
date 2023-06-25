#include "monty.h"

/**
 * stack_pchar - prints the ASCII value of char at the top of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
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
