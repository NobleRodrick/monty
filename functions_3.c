#include "monty.h"
/**
 * nothing_function- does nothing, really nothing
 * @hd: head of defined stack
 * @cnt: counter
 * Return: nothing
 */
void nothing_function(stack_t **hd, unsigned int cnt)
{
	(void) cnt;
	(void) hd;
}

/**
 * subtract_function - gives the difference of the latest stack enteries
 * @hd: head of stack
 * @cnt: counter
 * Return: nothing
 */
void subtract_function(stack_t **hd, unsigned int cnt)
{
	stack_t *pal;
	int gd, node;

	pal = *hd;
	for (node = 0; pal != NULL; node++)
		pal = pal->next;
	if (node < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", cnt);
		fclose(cont.file);
		free(cont.content);
		freeStack(*hd);
		exit(EXIT_FAILURE);
	}
	pal = *hd;
	gd = pal->next->n - pal->n;
	pal->next->n = gd;
	*hd = pal->next;
	free(pal);
}

/**
 * divide_function - divides the first by second top element.
 * @hd: head of stack
 * @cnt: counter
 * Return: nothing
 */
void divide_function(stack_t **hd, unsigned int cnt)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", cnt);
		fclose(cont.file);
		free(cont.content);
		freeStack(*hd);
		exit(EXIT_FAILURE);
	}
	h = *hd;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", cnt);
		fclose(cont.file);
		free(cont.content);
		freeStack(*hd);
		exit(EXIT_FAILURE);
	}
	pal = h->next->n / h->n;
	h->next->n = pal;
	*hd = h->next;
	free(h);
}
