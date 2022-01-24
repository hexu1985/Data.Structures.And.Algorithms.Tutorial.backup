#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define N 10

void PrintList(Link);
Link Reverse(Link);

int main(void) 
{
	Link t, head;
	int i;

	t = malloc(sizeof(Node));
	if (t != NULL)
	{
		t->item = 1;
		t->next = NULL;
	}
	head = t;
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
	PrintList(head);
	head = Reverse(head);
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

Link Reverse(Link x)
{
	Link t, y = x, r = NULL;

	while (y != NULL)
	{
		t = y->next;
		y->next = r;
		r = y;
		y = t;
	}
	return r;
}
