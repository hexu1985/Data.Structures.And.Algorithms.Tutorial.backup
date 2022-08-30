#include "string_list.h"
#include <stdio.h>

void print(ItemType data) 
{
    printf("data: %s\n", data);
}

void test()
{
    SinglyLinkedList* words = NewList();
    ListAppend(words, "foo");
    ListAppend(words, "bar");
    ListAppend(words, "bim");
    ListAppend(words, "baz");
    ListAppend(words, "quux");

    printf("The origin list\n");
    ListTravel(words, &print);

    printf("Reverse the list\n");
    ListReverse(words);
    ListTravel(words, &print);

    FreeList(words);
}

int main()
{
    Init();

    test();

    return 0;
}
