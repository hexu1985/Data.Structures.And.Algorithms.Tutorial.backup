#include "integer_list.h"
#include <stdio.h>

void print1(ItemType data) {
    printf("Got this data: %d\n", data);
}

void print2(ItemType data) {
    printf("data: %d\n", data);
}

void test()
{
    printf("----------------------------%s---------------------------\n", __func__);

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
    ListTravel(numbers, &print1);

    if (ListSearch(numbers, 627))
        printf("Found 627 in the list.\n");
    if (ListSearch(numbers, 838))
        printf("Found 838 in the list.\n");
    
    printf("Now we try to Delete an item\n");
    ListDelete(numbers, 113);
    printf("List now has %d elements\n", ListCount(numbers));
    ListTravel(numbers, &print2);
    
    printf("Delete the first item in the list\n");
    ListDelete(numbers, 627);
    printf("size: %d\n", ListCount(numbers));
    ListTravel(numbers, &print2);
    
    printf("Delete the last item in the list\n");
    ListDelete(numbers, 515);
    printf("size: %d\n", ListCount(numbers));
    ListTravel(numbers, &print2);

    FreeList(numbers);
}

void test_reverse()
{
    printf("----------------------------%s---------------------------\n", __func__);

    SinglyLinkedList* numbers = NewList();
    ListAppend(numbers, 627);
    ListAppend(numbers, 758);
    ListAppend(numbers, 113);
    ListAppend(numbers, 101);
    ListAppend(numbers, 515);

    printf("The origin list\n");
    ListTravel(numbers, &print2);

    printf("Reverse the list\n");
    ListReverse(numbers);
    ListTravel(numbers, &print2);

    FreeList(numbers);
}

void test_sort()
{
    printf("----------------------------%s---------------------------\n", __func__);

    SinglyLinkedList* numbers = NewList();
    ListAppend(numbers, 627);
    ListAppend(numbers, 758);
    ListAppend(numbers, 113);
    ListAppend(numbers, 101);
    ListAppend(numbers, 515);

    printf("The origin list\n");
    ListTravel(numbers, &print2);

    printf("Sort the list\n");
    ListSort(numbers);
    ListTravel(numbers, &print2);

    FreeList(numbers);
}

int main()
{
    Init();

    test();
    test_reverse();
    test_sort();

    return 0;
}

