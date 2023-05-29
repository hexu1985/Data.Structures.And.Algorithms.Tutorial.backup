#include "string_list.h"
#include <stdio.h>

const char* prefix = "";

void print(ItemType data) 
{
    printf("%sdata: %s\n", prefix, data);
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
    prefix = "Got this ";
    ListTravel(words, &print);
    prefix = "";

    if (ListSearch(words, "foo"))
        printf("Found foo in the list.\n");
    if (ListSearch(words, "amiga"))
        printf("Found amiga in the list.\n");
    
    printf("Now we try to delete an item\n");
    ListDelete(words, "bim");
    printf("List now has %d elements\n", ListCount(words));
    ListTravel(words, &print);
    
    printf("delete the first item in the list\n");
    ListDelete(words, "foo");
    printf("size: %d\n", ListCount(words));
    ListTravel(words, &print);
    
    printf("delete the last item in the list\n");
    ListDelete(words, "quux");
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

