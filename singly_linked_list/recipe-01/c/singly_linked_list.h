#pragma once

#include <stdbool.h>

// """ A singly-linked node. """
struct Node {
    Node* next;
    ItemType data;
};

// provide by user
Node* NewNode(ItemType);
void FreeNode(Node*);

bool IsEqualItem(ItemType, ItemType);
ItemType CopyItem(ItemType);

// """ A singly-linked list. """
struct SinglyLinkedList {
    Node* head;
    Node* tail;
    int count;
};

// """ Create an empty list. """
SinglyLinkedList* NewList();
void FreeList(SinglyLinkedList*);

// """ Iterate through the list. """
void Travel(SinglyLinkedList*, void (*travel)(ItemType));

// """ Append an item to the list """
void Append(SinglyLinkedList*, ItemType);

// """ Delete a node from the list """
void Delete(SinglyLinkedList*, ItemType);

// """ Search through the list. Return True if data is found, otherwise
// False. """
bool Search(SinglyLinkedList*, ItemType);

ItemType GetItem(SinglyLinkedList*, int index);
void SetItem(SinglyLinkedList*, int index, ItemType);
