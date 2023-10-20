#include "monty.h"
/**
 * pchar_function - prints the char at the top of the stack,
 * followed by a new line
 * @hd: head of defined stack
 * @cnt: counter
 * Return: nothing
 */
void pchar_function(stack_t **hd, unsigned int cnt)
{
	stack_t *h;

	h = *hd;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", cnt);
		fclose(cont.file);
		free(cont.content);
		freeStack(*hd);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", cnt);
		fclose(cont.file);
		free(cont.content);
		freeStack(*hd);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

/**
 * rotate_function - fuction rotates the stack to top
 * @hd: head of stack
 * @cnt: counter
 * Return: nothing
 */
void rotate_function(stack_t **hd,  __attribute__((unused)) unsigned int cnt)
{
	stack_t *temp = *hd, *pal;

	if (*hd == NULL || (*hd)->next == NULL)
	{
		return;
	}
	pal = (*hd)->next;
	pal->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *hd;
	(*hd)->next = NULL;
	(*hd)->prev = temp;
	(*hd) = pal;
}

/**
 * bottom_rotate - rotates the stack to the bottom
 * @hd: head of stack
 * @cnt: counter
 * Return: no return
 */
void bottom_rotate(stack_t **hd, __attribute__((unused)) unsigned int cnt)
{
	stack_t *clone;

	clone = *hd;
	if (*hd == NULL || (*hd)->next == NULL)
	{
		return;
	}
	while (clone->next)
	{
		clone = clone->next;
	}
	clone->next = *hd;
	clone->prev->next = NULL;
	clone->prev = NULL;
	(*hd)->prev = clone;
	(*hd) = clone;
}
