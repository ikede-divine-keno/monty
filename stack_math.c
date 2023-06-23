/**
 * stack_div - divides tge second top element of stack by the top element
 * @stack: pointer to lists for monty stack
 * @line_num: number of line opcode occurs on
 */
void stack_div(stack_t **stack, unsigned int line_num)
{
	int div = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		free(diff.buffer);
		fclose(diff.f);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free(diff.buffer);
		fclose(diff.f);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		div = (*stack)->n;
		stack_pop(stack, line_num);
		(*stack)->n /= div;
	}
}

/**
 * stack_mod - rest of division of the second top element of a stack by the top
 * @stack: pointer to lists for monty stack
 * @line_num: number of line opcode occurs on
 */
void stack_mod(stack_t **stack, unsigned int line_num)
{
	int mod = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		free(diff.buffer);
		fclose(diff.f);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free(diff.buffer);
		fclose(diff.f);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		mod = (*stack)->n;
		stack_pop(stack, line_num);
		(*stack)->n %= mod;
	}
}
