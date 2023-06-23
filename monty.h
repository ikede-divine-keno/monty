#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/mman.h>

/*--- Struct Definitions ---*/
extern int arg_stack;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globe_var - opcoode and its function
 * @f: the opcode
 * @arg_stack: function to handle the opcode
 * @buffer: pointer to
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct diff_s
{
	FILE *f;
	int arg_stack;
	char *buffer;
} diff_t;

extern diff_t diff;

void read_file(char *fileptr, stack_t **stack);
char *parse_line(char *line, stack_t **stack, unsigned int line_num);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_num);
instruct_func op_func_obt(char *s);

void stack_pall(stack_t **stack, unsigned int line_num);
void stack_push(stack_t **stack, unsigned int line_num);
void stack_pint(stack_t **stack, unsigned int line_num);
void stack_pop(stack_t **stack, unsigned int line_num);
void free_stack(stack_t *head);
void stack_swap(stack_t **stack, unsigned int line_num);
void stack_add(stack_t **stack, unsigned int line_num);
void stack_nop(stack_t **stack, unsigned int line_num);
void stack_sub(stack_t **stack, unsigned int line_num);
#endif
