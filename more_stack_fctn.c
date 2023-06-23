#include "monty.h"
/**
 * stack_swap - swaps the top two elements of the stack.
 * @stack: pointer to lists for monty stack
 * @line_num: number of line opcode occurs on
 */

void stack_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *printer;
	int tmp;

	printer = *stack;
	if (printer == NULL || printer->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = printer->n;
	printer->n = printer->next->n;
	printer->next->n = tmp;
}

/**
 * stack_add - adds the top two elements of the stack.
 * @stack: pointer to lists for monty stack
 * @line_num: number of line opcode occurs on
 */

void stack_add(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	int sum = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	stack_pop(stack, line_num);

	(*stack)->n = sum;
}

/**
 * @stack_nop - this opcode does not do anything.
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void stack_nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_num)
{
	;
}

/**
 * stack_sub - subtract the top element of the stack from the second.
 * @stack: pointer to lists for monty stack
 * @line_num: number of line opcode occurs on
 */
void stack_sub(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	int sub = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	stack_pop(stack, line_num);

	(*stack)->n = sub;
}

