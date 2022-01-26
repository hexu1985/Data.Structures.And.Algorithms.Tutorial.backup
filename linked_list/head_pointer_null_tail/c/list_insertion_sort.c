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

Link InsertionSort(Link x)
{
    Link head;
    Link t, u, y;
    Link *next_ref;
    head = NULL;
    for (t = x; t != NULL; t = u)
    {
        u = t->next;
        for (next_ref = &head, y = *next_ref; y != NULL; next_ref = &y->next, y = y->next) 
            if (y->item > t->item) 
                break;
        t->next = y;
        *next_ref = t;
    }
    return head;
}

