#include "monty.h"
/**
 * stack_function -  sets the format of the data to a stack (LIFO)
 * @hd: head of stack
 * @cnt: counter
 * Return: no return
 */
void stack_function(stack_t **hd, unsigned int cnt)
{
	(void)hd;
	(void)cnt;
	cont.dott = 0;
}

/**
 * queue_function - sets the format of the data to a queue (FIFO)
 * @hd: queue head
 * @cnt: counter
 * Return: no return
 */
void queue_function(stack_t **hd, unsigned int cnt)
{
	(void)hd;
	(void)cnt;
	cont.dott = 1;
}

/**
 * tail_add - enqueues a given node< puts at the tail
 * @n: new node
 * @hd: head of the stack
 * Return: no return
 */
void tail_add(stack_t **hd, int n)
{
	stack_t *latest_node, *pal;

	pal = *hd;
	latest_node = malloc(sizeof(stack_t));
	if (latest_node == NULL)
	{
		printf("Error\n");
	}
	latest_node->n = n;
	latest_node->next = NULL;
	if (pal)
	{
		while (pal->next)
			pal = pal->next;
	}
	if (!pal)
	{
		*hd = latest_node;
		latest_node->prev = NULL;
	}
	else
	{
		pal->next = latest_node;
		latest_node->prev = pal;
	}
}
