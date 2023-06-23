#include "monty.h"
/**
 * stack_push - push an element to a stack.
 * @stack: linked lists for monty stack
 * @line_num: number of line opcode occurs on
 */
void stack_push(stack_t **stack, unsigned int line_num)
{
	stack_t *top;
	(void)line_num;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = diff.arg_stack;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * stack_pall - print all the values of the stack starting from the top..
 * @stack: pointer to linked list stack
 * @line_num: number of line opcode occurs on
 */
void stack_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *printer;
	(void)line_num;

	printer = *stack;
	while (printer != NULL)
	{
		printf("%d\n", printer->n);
		printer = printer->next;
	}
}

/**
 * stack_pint - print the value at the top of stack followed by a new line.
 * @stack: pointer to linked list stack
 * @line_num: number of line opcode occurs on
 *
 */
void stack_pint(stack_t **stack, unsigned int line_num)
{
	stack_t *printer;

	printer = *stack;
	if (printer == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", printer->n);
}

/**
 * stack_pop - remove the top element from a stack.
 *@stack: pointer to first node
 *@line_num: integer
 */
void stack_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *rem = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	*stack = rem->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(rem);
}

/**
 * free_stack - free a stack
 * @head: pointer to first node
 *
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
