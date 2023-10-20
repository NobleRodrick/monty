#include "monty.h"
/**
 * codemap_function - the one in charge of execution
 * @stack: head linked list - stack
 * @cnt: counter
 * @file: indicates location of monty file
 * @content: what is in the line
 * Return: no return
 */
int codemap_function(char *content, stack_t **stack, unsigned int cnt, FILE *file)
{
	instruction_t op_dict[] = {
		{"push", push_function},
		{"pall", print_all},
		{"pint", print_top},
		{"pop", pop_function},
		{"swap", swap_function},
		{"add", add_function},
		{"nop", nothing_function},
		{"sub", subtract_function},
		{"div", divide_function},
		{"mul", multiply_function},
		{"mod", mod_function},
		{"pchar", pchar_function},
		{"pstr", pstr_function},
		{"rotl", rotate_function},
		{"rotr", bottom_rotate},
		{"queue", queue_function},
		{"stack", stack_function},
		{NULL, NULL}
				};
	unsigned int i = 0;
	char *operator;

	operator = strtok(content, " \n\t");
	if (operator && operator[0] == '#')
		return (0);
	cont.arg = strtok(NULL, " \n\t");
	while (op_dict[i].opcode && operator)
	{
		if (strcmp(operator, op_dict[i].opcode) == 0)
		{
			op_dict[i].f(stack, cnt);
			return (0);
		}
		i++;
	}
	if (operator && op_dict[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", cnt, operator);
		fclose(file);
		free(content);
		freeStack(*stack);
		exit(EXIT_FAILURE); }
		return (1);
}
