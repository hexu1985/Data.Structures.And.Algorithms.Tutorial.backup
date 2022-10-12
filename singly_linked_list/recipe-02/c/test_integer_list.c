#include "integer_list.h"
#include <stdio.h>

void print(ItemType data)
{
    printf("data: %d\n", data);
}

void test()
{
    SinglyLinkedList* numbers = NewList();
    ListAppend(numbers, 627);
    ListAppend(numbers, 758);
    ListAppend(numbers, 113);
    ListAppend(numbers, 101);
    ListAppend(numbers, 515);

    printf("access by index\n");
    printf("here is a node: %d\n", ListGetItem(numbers, 1));
    
    printf("modify by index\n");
    ListSetItem(numbers, 4, 1515);
    printf("Modified node by index: %d\n", ListGetItem(numbers, 4));

    printf("This list has %d elements.\n", ListCount(numbers));
    ListTravel(numbers, &print);

    if (ListSearch(numbers, 627))
        printf("Found 627 in the list.\n");
    if (ListSearch(numbers, 838))
        printf("Found 838 in the list.\n");
    
    printf("Now we try to delete an item\n");
    ListDelete(numbers, 113);
    printf("List now has %d elements\n", ListCount(numbers));
    ListTravel(numbers, &print);
    
    printf("delete the first item in the list\n");
    ListDelete(numbers, 627);
    printf("size: %d\n", ListCount(numbers));
    ListTravel(numbers, &print);
    
    printf("delete the last item in the list\n");
    ListDelete(numbers, 515);
    printf("size: %d\n", ListCount(numbers));
    ListTravel(numbers, &print);

    FreeList(numbers);
}

int main()
{
    Init();

    test();

    return 0;
}

