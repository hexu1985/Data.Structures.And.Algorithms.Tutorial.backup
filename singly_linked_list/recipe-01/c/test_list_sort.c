#include "integer_list.h"
#include <stdio.h>
#include <stdlib.h>

#define N 10

void print(ItemType data) 
{
    printf("%d ", data);
}

void test()
{
    SinglyLinkedList* numbers = NewList();
    for (int i = 0; i < N-1; i++) {
        ListAppend(numbers, rand() % 1000);
    }

    ListTravel(numbers, &print);
    printf("\n");

    ListSort(numbers);

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

