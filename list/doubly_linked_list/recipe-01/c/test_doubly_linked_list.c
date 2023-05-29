#include "string_list.h"

void test()
{
    DoublyLinkedList* dll = NewList();
    ListAppend(dll, "foo");
    ListAppend(dll, "bar");
    ListAppend(dll, "biz");
    ListAppend(dll, "whew");

    printf("Items in List : \n");
    ListPrintFoward(dll);

    printf("List after deleting node with data whew\n");
    ListDelete(dll, "whew");
    ListPrintFoward(dll);

    printf("List count: %d\n", ListCount(dll));
    printf("Print list backwards\n");
    ListPrintBackward(dll);

    printf("Reverse list \n" );
    ListReverse(dll);
    ListPrintFoward(dll);

    printf("Append item to front of list\n");
    ListInsertHead(dll, "55");
    ListPrintFoward(dll);

    printf("Get First element: %s\n", ListGetItem(dll, 0));

    FreeList(dll);
}

int main()
{
    Init();

    test();

    return 0;
}

