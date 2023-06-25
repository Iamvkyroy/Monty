#include "monty.h"
/**
 * f_div - divides two elements at the top of the stack
 *
 * @head: head of stack
 *
 * @counter: line number
 *
 * Return: 0
*/
void f_div(stack_t **head, unsigned int counter)
{
int len = 0, aux;
stack_t *h;

h = *head;
while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't div, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
if (h->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
aux = h->next->n / h->n;
h->next->n = aux;
*head = h->next;
free(h);
}
