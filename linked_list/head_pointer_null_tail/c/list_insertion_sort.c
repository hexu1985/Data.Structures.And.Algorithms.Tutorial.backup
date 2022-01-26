#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void PrintList(Link);
Link InsertionSort(Link);

int main(void) 
{
	Link t, head;
	int i;

	t = malloc(sizeof(Node));
	if (t != NULL)
	{
		t->item = rand() % 1000;
		t->next = NULL;
	}
	head = t;
	for (i = 2; i < N+1; i++)
	{
		t->next = malloc(sizeof *t);
        if (t->next != NULL) 
        {
            t = t->next;
            t->next = NULL;
            t->item = rand() % 1000;
        }
	}
	PrintList(head);
	head = InsertionSort(head);
	PrintList(head);
	return 0;
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

Link InsertionSort(Link head)
{
    Link headb;
	Link t, u, x;
    Link *next_ref;
    headb = NULL;
    for (t = head; t != NULL; t = u)
    {
        u = t->next;
        for (next_ref = &headb, x = *next_ref; x != NULL; next_ref = &x->next, x = x->next) 
            if (x->item > t->item) 
                break;
        t->next = x;
        *next_ref = t;
    }
    return headb;
}
