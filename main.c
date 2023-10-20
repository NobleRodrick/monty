#include "monty.h"

cont_t cont = {NULL, NULL, NULL, 0};

/**
 * main - our monty code interpreter
 * @argc: argument cnt
 * @argv: argumet vector location
 * Return: 0, in case of success
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t note_line = 1;
	stack_t *stack = NULL;
	unsigned int cnt = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	cont.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (note_line > 0)
	{
		content = NULL;
		note_line = getline(&content, &size, file);
		cont.content = content;
		cnt++;
		if (note_line > 0)
		{
			codemap_function(content, &stack, cnt, file);
		}
		free(content);
	}
	freeStack(stack);
	fclose(file);
	return (0);
}
