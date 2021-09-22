#include "monty.h"

/**
 * main - Program entry point.
 * @argc: number of arguments.
 * @argv: arguments.
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	char *buffer = NULL;
	size_t BUF_SIZE = 0;
	ssize_t nread;
	FILE *stream;
	stack_t *head = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
		print_errors(0, NULL, 0);
	stream = fopen(argv[1], "r");
	if (!stream)
		print_errors(1, argv[1], 0);
	while ((nread = getline(&buffer, &BUF_SIZE, stream)) != -1)
	{
		line_number++;
		if (*buffer == '\n' && *buffer == '#')
			continue;
		arguments.command = strtok(buffer, "\n ");
		if (!arguments.command ||
			strcmp(arguments.command, "nop") == 0 || *arguments.command == '#')
			continue;
		arguments.value = strtok(NULL, "\n ");
		get_opcode(&head, line_number);
	}
	free_stuff(buffer, head);
	fclose(stream);
	return (0);
}
