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

    SinglyLinkedList* words = NewList();
    ListAppend(words, 627);
    ListAppend(words, 758);
    ListAppend(words, 113);
    ListAppend(words, 101);
    ListAppend(words, 515);

    printf("access by index\n");
    printf("here is a node: %d\n", ListGetItem(words, 1));
    
    printf("modify by index\n");
    ListSetItem(words, 4, 1515);
    printf("Modified node by index: %d\n", ListGetItem(words, 4));

    printf("This list has %d elements.\n", ListCount(words));
    ListTravel(words, &print1);

    if (ListSearch(words, 627))
        printf("Found 627 in the list.\n");
    if (ListSearch(words, 838))
        printf("Found 838 in the list.\n");
    
    printf("Now we try to Delete an item\n");
    ListDelete(words, 113);
    printf("List now has %d elements\n", ListCount(words));
    ListTravel(words, &print2);
    
    printf("Delete the first item in the list\n");
    ListDelete(words, 627);
    printf("size: %d\n", ListCount(words));
    ListTravel(words, &print2);
    
    printf("Delete the last item in the list\n");
    ListDelete(words, 515);
    printf("size: %d\n", ListCount(words));
    ListTravel(words, &print2);

    FreeList(words);
}

void test_reverse()
{
    printf("----------------------------%s---------------------------\n", __func__);

    SinglyLinkedList* words = NewList();
    ListAppend(words, 627);
    ListAppend(words, 758);
    ListAppend(words, 113);
    ListAppend(words, 101);
    ListAppend(words, 515);

    printf("The origin list\n");
    ListTravel(words, &print2);

    printf("Reverse the list\n");
    ListReverse(words);
    ListTravel(words, &print2);

    FreeList(words);
}

void test_sort()
{
    printf("----------------------------%s---------------------------\n", __func__);

    SinglyLinkedList* words = NewList();
    ListAppend(words, 627);
    ListAppend(words, 758);
    ListAppend(words, 113);
    ListAppend(words, 101);
    ListAppend(words, 515);

    printf("The origin list\n");
    ListTravel(words, &print2);

    printf("Sort the list\n");
    ListSort(words);
    ListTravel(words, &print2);

    FreeList(words);
}

int main()
{
    Init();

    test();
    test_reverse();
    test_sort();

    return 0;
}

