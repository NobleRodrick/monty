#include "monty.h"
/**
 * addnode_function - increments a stack by a new node
 * @hd: stack head
 * @n: value to add, node
 * Return: nothing
 */
void addnode_function(stack_t **hd, int n)
{

	stack_t *latest_node, *pal;

	pal = *hd;
	latest_node = malloc(sizeof(stack_t));
	if (latest_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (pal != NULL)
		pal->prev = latest_node;
	latest_node->n = n;
	latest_node->next = *hd;
	latest_node->prev = NULL;
	*hd = latest_node;
}

/**
 * freeStack - code to free the dlist
 * @hd: stack head node
 */
void freeStack(stack_t *hd)
{
	stack_t *pal;

	pal = hd;
	while (hd != NULL)
	{
		pal = hd->next;
		free(hd);
		hd = pal;
	}
}
