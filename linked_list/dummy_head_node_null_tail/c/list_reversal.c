#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define N 10

void PrintList(Link);
Link ReverseNext(Link);

int main(void) 
{
	Link t;
    Node head;
	int i;

	t = malloc(sizeof(Node));
	if (t != NULL)
	{
		t->item = 1;
		t->next = NULL;
	}
	head.next = t;
	for (i = 2; i < N+1; i++)
	{
		t->next = malloc(sizeof(Node));
		if (t->next != NULL)
		{
			t = t->next;
			t->item = i;
			t->next = NULL;
		}
	}
	PrintList(head.next);
	head.next = ReverseNext(&head);
	PrintList(head.next);
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

Link ReverseNext(Link x)
{
    Node head;
    Link t, y;
    y = &head;
    y->next = NULL;
    while (x->next != NULL) {
        t = x->next;
        x->next = t->next;

        t->next = y->next;
        y->next = t;
    }

    return y->next;
}
