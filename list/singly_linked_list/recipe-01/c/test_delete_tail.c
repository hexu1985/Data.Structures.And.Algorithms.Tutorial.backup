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
    printf("size: %d\n", ListCount(words));
    ListTravel(words, &print);

    printf("Delete the last item in the list\n");
    ListDelete(words, "quux");
    printf("size: %d\n", ListCount(words));
    ListTravel(words, &print);

    printf("append another item\n");
    ListAppend(words, "Quux");
    printf("size: %d\n", ListCount(words));
    ListTravel(words, &print);

    FreeList(words);
}

int main()
{
    Init();

    test();

    return 0;
}


