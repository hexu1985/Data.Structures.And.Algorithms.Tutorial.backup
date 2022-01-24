#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int i, N = atoi(argv[1]), M = atoi(argv[2]);
	Link t = malloc(sizeof *t), x = t;

	t->item = 1; t->next = t;
	for (i = 2; i <= N; i++)
	{
		x = (x->next = malloc(sizeof *x));
		x->item = i;
		x->next = t;
	}
	while (x != x->next)
	{
		for (i = 1; i < M; i++)
			x = x->next;
		x->next = x->next->next;
		N--;
	}
	printf("%d\n", x->item);
	return 0;
}

