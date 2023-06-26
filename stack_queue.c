#include "monty.h"
/**
 * queue_stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void queue_stack(stack_t **stack, unsigned int line_num)
{
	(*stack)->n = STACK;
	(void)line_num;
}

/**
 * monty_queue - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void stack_queue(stack_t **stack, unsigned int line_num)
{
	(*stack)->n = QUEUE;
	(void)line_num;
}
