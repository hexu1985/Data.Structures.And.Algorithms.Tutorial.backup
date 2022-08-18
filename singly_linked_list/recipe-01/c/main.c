#include "singly_linked_list_string.h"
#include <stdio.h>

void print1(ItemType data) {
    printf("Got this data: %s\n", data);
}

void print2(ItemType data) {
    printf("data: %s\n", data);
}

int main()
{
    SinglyLinkedList* words = NewList();
    Append(words, "foo");
    Append(words, "bar");
    Append(words, "bim");
    Append(words, "baz");
    Append(words, "quux");

    printf("access by index\n");
    printf("here is a node: %s\n", GetItem(words, 1));
    
    printf("modify by index\n");
    SetItem(words, 4, "Quux", &SetData);
    printf("Modified node by index: %s\n", GetItem(words, 4));

    printf("This list has %d elements.\n", Count(words));
    Travel(words, &print1);

    if (Search(words, "foo", &IsEqual))
        printf("Found foo in the list.\n");
    if (Search(words, "amiga", &IsEqual))
        printf("Found amiga in the list.\n");
    
    printf("Now we try to Delete an item\n");
    Delete(words, "bim", &IsEqual);
    printf("List now has %d elements\n", Count(words));
    Travel(words, &print2);
    
    printf("Delete the first item in the list\n");
    Delete(words, "foo", &IsEqual);
    printf("size: %d\n", Count(words));
    Travel(words, &print2);
    
    printf("Delete the last item in the list\n");
    Delete(words, "quux", &IsEqual);
    printf("size: %d\n", Count(words));
    Travel(words, &print2);

    FreeList(words);

    return 0;
}

