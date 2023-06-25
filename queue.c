#include "monty.h"
/**
 * f_queue - prints the beginning of the stack
 *
 * @head: head of stack
 *
 * @counter: line number
 *
 * Return: 0
*/
void f_queue(stack_t **head, unsigned int counter)
{
bus.lifi = 1;
(void)head;
(void)counter;
}

/**
 * addqueue - addition to the  tail of the  stack
 *
 * @n: new value
 *
 * @head: head of stack
 *
 * Return: 0
*/
void addqueue(stack_t **head, int n)
{
stack_t *new_node, *aux;

aux = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
}
new_node->n = n;
new_node->next = NULL;
if (aux)
{
while (aux->next)
aux = aux->next;
}
if (!aux)
{
*head = new_node;
new_node->prev = NULL;
}
else
{
aux->next = new_node;
new_node->prev = aux;
}
}
