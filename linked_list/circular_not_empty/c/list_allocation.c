#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[]) 
{
	int i, N = atoi(argv[1]), M = atoi(argv[2]);
	Link t, x;

	InitNodes(N);
	for (i = 2, x = NewNode(1), x->next = x; i <= N; i++)
	{
		t = NewNode(i);
		InsertNext(x, t);
		x = t;
	}

	while (x != Next(x))
	{
		for (i = 1;  i < M; i++)
			x = Next(x);
		FreeNode(DeleteNext(x));
	}

	printf("%d\n", Item(x));
	return 0;
}
