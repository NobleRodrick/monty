#include "monty.h"
/**
 * push_function - adds ode to rear of stack
 * @hd: head of stack
 * @cnt: numberer
 * Return: nothing
 */
void push_function(stack_t **hd, unsigned int cnt)
{
	int i, j = 0, signal = 0;

	if (cont.arg)
	{
		if (cont.arg[0] == '-')
			j++;
		for (; cont.arg[j] != '\0'; j++)
		{
			if (cont.arg[j] > 57 || cont.arg[j] < 48)
				signal = 1; 
		}
		if (signal == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", cnt);
			fclose(cont.file);
			free(cont.content);
			freeStack(*hd);
			exit(EXIT_FAILURE); }
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", cnt);
		fclose(cont.file);
		free(cont.content);
		freeStack(*hd);
		exit(EXIT_FAILURE);
	}
	i = atoi(cont.arg);
	if (cont.dott == 0)
		addnode_function(hd, i);
	else
		tail_add(hd, i);
}

/**
 * print_all - prints all the values of the stack
 * @hd: haed of stack
 * @cnt: counter
 * Return: nothing
 */
void print_all(stack_t **hd, unsigned int cnt)
{
	stack_t *h;
	(void)cnt;

	h = *hd;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * print_top - prints the value of stack top
 * @hd: head of stack
 * @cnt: counter
 * Return: nothing
 */
void print_top(stack_t **hd, unsigned int cnt)
{
	if (*hd == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", cnt);
		fclose(cont.file);
		free(cont.content);
		freeStack(*hd);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*hd)->n);
}