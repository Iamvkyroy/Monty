#include "monty.h"
/**
 * f_pstr - prints the first line of the string
 * @counter: line_number
 *
 * @head: head of stack
 *
 * Return: 0
*/
void f_pstr(stack_t **head, unsigned int counter)
{
stack_t *h;
(void)counter;

h = *head;
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
