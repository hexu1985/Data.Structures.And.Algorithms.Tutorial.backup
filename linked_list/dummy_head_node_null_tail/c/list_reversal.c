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

Link ReverseNext(Link head)
{
    Node tmp;
    Link b = &tmp;
    Link t;
    b->next = NULL;
    while (head->next != NULL) {    // head指向的list不为空
        t = head->next;             // 从head指向的list的头部删除节点
        head->next = t->next;
        t->next = b->next;           // 向b指向的list的头部插入节点
        b->next = t;
    }

    return b->next;
}
