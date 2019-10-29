#include "sort.h"

/**
 * swap - swaps two nodes in a linked list
 * @list: pointer to doubly linked list
 * @a: pointer to first node
 * @b: pointer to second node
 */
void swap(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *aprev = a->prev;
	listint_t *bnext = b->next;

	if (aprev)
		aprev->next = b;
	if (bnext)
		bnext->prev = a;

	a->prev = b;
	b->prev = aprev;
	a->next = bnext;
	b->next = a;

	if (b->prev == NULL)
		*list = b;
}

void cocktail_sort_list(listint_t **list)
{
    listint_t *copy = *list;
    int swapped = 1;

    while (swapped)
    {
        swapped = 0;

        for (;copy->next; copy = copy->next)
        {
            if (copy->n > copy->next->n)
            {
                swap(list, copy, copy->next);
                swapped = 1;
            }
        }
        copy = copy->prev;

        for (;copy->prev; copy = copy->prev)
        {
            if (copy->n < copy->prev->n)
            {
                swap(list, copy, copy->prev);
                swapped = 1;
            }
        }
        copy = copy->next;
    }
}
