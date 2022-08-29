#include "string_list.h"
#include <stdio.h>

void print2(ItemType data) {
    printf("data: %s\n", data);
}

void test_delete_tail()
{
    printf("----------------------------%s---------------------------\n", __func__);

    SinglyLinkedList* words = NewList();
    ListAppend(words, "foo");
    ListAppend(words, "bar");
    ListAppend(words, "bim");
    ListAppend(words, "baz");
    ListAppend(words, "quux");

    printf("The origin list\n");
    printf("size: %d\n", ListCount(words));
    ListTravel(words, &print2);

    printf("Delete the last item in the list\n");
    ListDelete(words, "quux");
    printf("size: %d\n", ListCount(words));
    ListTravel(words, &print2);

    printf("append another item\n");
    ListAppend(words, "Quux");
    printf("size: %d\n", ListCount(words));
    ListTravel(words, &print2);

    FreeList(words);
}

int main()
{
    Init();

    test_delete_tail();

    return 0;
}


