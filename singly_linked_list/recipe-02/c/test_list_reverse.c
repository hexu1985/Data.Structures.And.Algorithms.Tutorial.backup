#include "integer_list.h"
#include <stdio.h>

#define N 10

void print(ItemType data) 
{
    printf("%d ", data);
}

void test()
{
    SinglyLinkedList* numbers = NewList();
    for (int i = 2; i < N+1; i++) {
        ListAppend(numbers, i);
    }

    ListTravel(numbers, &print);
    printf("\n");

    ListReverse(numbers);

    ListTravel(numbers, &print);
    printf("\n");

    FreeList(numbers);
}

int main()
{
    Init();

    test();

    return 0;
}
