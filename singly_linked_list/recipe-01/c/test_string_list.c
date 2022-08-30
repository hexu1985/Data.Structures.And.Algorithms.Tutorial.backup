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

    printf("access by index\n");
    printf("here is a node: %s\n", ListGetItem(words, 1));
    
    printf("modify by index\n");
    ListSetItem(words, 4, "Quux");
    printf("Modified node by index: %s\n", ListGetItem(words, 4));

    printf("This list has %d elements.\n", ListCount(words));
    ListTravel(words, &print);

    if (ListSearch(words, "foo"))
        printf("Found foo in the list.\n");
    if (ListSearch(words, "amiga"))
        printf("Found amiga in the list.\n");
    
    printf("Now we try to Delete an item\n");
    ListDelete(words, "bim");
    printf("List now has %d elements\n", ListCount(words));
    ListTravel(words, &print);
    
    printf("Delete the first item in the list\n");
    ListDelete(words, "foo");
    printf("size: %d\n", ListCount(words));
    ListTravel(words, &print);
    
    printf("Delete the last item in the list\n");
    ListDelete(words, "Quux");
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

