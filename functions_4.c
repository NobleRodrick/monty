#include "monty.h"
/**
 * multiply_function - multiplies the top two latest elements of the stack.
 * @hd: head of stack
 * @cnt: counter
 * Return: nothing
 */
void multiply_function(stack_t **hd, unsigned int cnt)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", cnt);
		fclose(cont.file);
		free(cont.content);
		freeStack(*hd);
		exit(EXIT_FAILURE);
	}
	h = *hd;
	pal = h->next->n * h->n;
	h->next->n = pal;
	*hd = h->next;
	free(h);
}

/**
 * mod_function - finds the modulo of the first element wrt the second
 * in a stack
 * @hd: head of stack
 * @cnt: counter
 * Return: nothing
 */
void mod_function(stack_t **hd, unsigned int cnt)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", cnt);
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
	pal = h->next->n % h->n;
	h->next->n = pal;
	*hd = h->next;
	free(h);
}

/**
 * pstr_function - prints a string starting at the top of the stack,
 * we complete this witha new line
 * @hd: head of stack
 * @cnt: counter
 * Return: nothing
 */
void pstr_function(stack_t **hd, unsigned int cnt)
{
	stack_t *h;
	(void)cnt;

	h = *hd;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
