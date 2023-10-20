#include "monty.h"
/**
 * pop_function - removes top of stack
 * @hd: head of stack
 * @cnt: counter
 * Return: nothing
 */
void pop_function(stack_t **hd, unsigned int cnt)
{
	stack_t *h;

	if (*hd == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", cnt);
		fclose(cont.file);
		free(cont.content);
		freeStack(*hd);
		exit(EXIT_FAILURE);
	}
	h = *hd;
	*hd = h->next;
	free(h);
}

/**
 * swap_function - interchanges rhe top two elements of a stack.
 * @hd: head of stack
 * @cnt: counter
 * Return: nothing
 */
void swap_function(stack_t **hd, unsigned int cnt)
{
	stack_t *h;
	int length = 0, pal;

	h = *hd;
	while (h != NULL)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", cnt);
		fclose(cont.file);
		free(cont.content);
		freeStack(*hd);
		exit(EXIT_FAILURE);
	}
	h = *hd;
	pal = h->n;
	h->n = h->next->n;
	h->next->n = pal;
}

/**
 * add_function - the two latest stack elements.
 * @hd: head of defined stack
 * @cnt: counter
 * Return: nothing
 */
void add_function(stack_t **hd, unsigned int cnt)
{
	stack_t *h;
	int length = 0, pal;

	h = *hd;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", cnt);
		fclose(cont.file);
		free(cont.content);
		freeStack(*hd);
		exit(EXIT_FAILURE);
	}
	h = *hd;
	pal = h->n + h->next->n;
	h->next->n = pal;
	*hd = h->next;
	free(h);
}