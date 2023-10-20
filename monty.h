#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
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
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct cont_s - stores some important function variables
 * @arg: argument
 * @file: pointer to monty file
 * @content: line content
 * @dott: flag change stack or queue
 * Description: carries values through the program
 */
typedef struct cont_s
{
	char *arg;
	FILE *file;
	char *content;
	int dott;
} cont_t;
extern cont_t cont;

void push_function(stack_t **hd, unsigned int cnt);
void print_all(stack_t **hd, unsigned int cnt);
void print_top(stack_t **hd, unsigned int cnt);
int codemap_function(char *content, stack_t **hd, unsigned int cnt, FILE *file);
void freeStack(stack_t *hd);
void pop_function(stack_t **hd, unsigned int cnt);
void swap_function(stack_t **hd, unsigned int cnt);
void add_function(stack_t **hd, unsigned int cnt);
void nothing_function(stack_t **hd, unsigned int cnt);
void subtract_function(stack_t **hd, unsigned int cnt);
void divide_function(stack_t **hd, unsigned int cnt);
void multiply_function(stack_t **hd, unsigned int cnt);
void mod_function(stack_t **hd, unsigned int cnt);
void pchar_function(stack_t **hd, unsigned int cnt);
void pstr_function(stack_t **hd, unsigned int cnt);
void rotate_function(stack_t **hd, unsigned int cnt);
void bottom_rotate(stack_t **hd, __attribute__((unused)) unsigned int cnt);
void addnode_function(stack_t **hd, int n);
void tail_add(stack_t **hd, int n);
void queue_function(stack_t **hd, unsigned int cnt);
void stack_function(stack_t **hd, unsigned int cnt);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
#endif
