#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void PrintList(Link);
Link InsertionSortNext(Link);

int main(void) 
{
	Node heada, headb;
	Link t, a;
	int i;

	a = &heada;
	for (i = 0, t = a; i < N-1; i++)
	{
		t->next = malloc(sizeof *t);
		t = t->next;
		t->next = NULL;
		t->item = rand() % 1000;
	}
	PrintList(heada.next);
    headb.next = InsertionSortNext(&heada);
	PrintList(headb.next);
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

Link InsertionSortNext(Link head)
{
	Link t, u, x, a, b;
    Node tmp;
	a = head;
	b = &tmp;
	b->next = NULL;
	for (t = a->next; t != NULL; t = u)
	{
		u = t->next;
		for (x = b; x->next != NULL; x = x->next)
			if (x->next->item > t->item)
				break;
		t->next = x->next;
		x->next = t;
	}
    a->next = NULL;
    return b->next;
}
