#include "monty.h"

/**
 * _pchar -  prints the char at the top of the stack
 * @head: pointer to head node of stack
 * @line_number: number of the line parsed.
 */

void _pchar(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (*head)
	{
		if (tmp->n < 0 || tmp->n > 127)
		{
			errors1(14, line_number);
			return;
		}
		printf("%c\n", tmp->n);
		return;
	}
	errors1(15, line_number);
}
/**
 * _pstr - Function prints string starting at the top of stack
 * @head: pointer to head node of stack
 * @line_number: number of the line parsed.
 */
void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	(void) line_number;

	if (!*head)
	{
		printf("\n");
		return;
	}
	while (tmp)
	{
		if (tmp->n == 0 || tmp->n < 0 || tmp->n > 126)
		{
			printf("\n");
			return;
		}
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
/**
 * _rotl - Function rotates the stack to the top
 * @head: pointer to head element of stack
 * @line_number: line number
 */
void _rotl(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head, *tmp1 = *head, *tmp2 = *head, *tmp3 = tmp->next;
	(void) line_number;

	if (tmp)
	{
		while (tmp)
		{
			tmp1 = tmp;
			tmp = tmp->next;
		}
		tmp1->next = tmp2;
		tmp2->next = NULL;
		tmp2->prev = tmp1;
		if (tmp3)
			(*head) = tmp3;
	}
}
/**
 * _rotr - function rotates the stack to the top
 * @head: head pointer of stack
 * @line_number: line number pointer
 */
void _rotr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp_first = *head, *tmp = *head, *tmp_last = NULL;
	(void) line_number;

	if (tmp)
	{
		if (tmp->next)
		{
			while (tmp)
			{
				tmp_last = tmp;
				tmp = tmp->next;
			}
			if (tmp_last->prev)
				tmp_last->prev->next = NULL;
			tmp_last->prev = NULL;
			tmp_last->next = tmp_first;
			tmp_first->prev = tmp_last;
			(*head) = tmp_last;
			return;
		}
		(*head) = tmp;
	}
}
