#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void PrintList(Link);
Link InsertionSortNext(Link);

int main(void) 
{
	Node head;
	Link t, a;
	int i;

	a = &head;
	for (i = 0, t = a; i < N-1; i++)
	{
		t->next = malloc(sizeof *t);
		t = t->next;
		t->next = NULL;
		t->item = rand() % 1000;
	}
	PrintList(head.next);
    head.next = InsertionSortNext(&head);
	PrintList(head.next);
}

void PrintList(Link t)
{
	while (t != NULL)
	{
		printf("%d ", t->item);
		t = t->next;
	}
	printf("\n");
}

Link InsertionSortNext(Link x)
{
    Node head;
	Link t, u, y;
    head.next = NULL;
	for (t = x->next; t != NULL; t = u)
	{
		u = t->next;
		for (y = &head; y->next != NULL; y = y->next)
			if (y->next->item > t->item)
				break;
		t->next = y->next;
		y->next = t;
	}
    x->next = NULL;
    return head.next;
}

