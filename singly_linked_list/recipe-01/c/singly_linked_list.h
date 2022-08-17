#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

// """ A singly-linked node. """
struct Node {
    Node* next;
    ItemType data;
};

// provide by user
Node* NewNode(ItemType);
void FreeNode(Node*);
bool IsEqualItem(ItemType, ItemType);

// """ A singly-linked list. """
struct SinglyLinkedList {
    Node* head;
    Node* tail;
    int count;
};

// """ Create an empty list. """
static SinglyLinkedList* NewList() {
    SinglyLinkedList* list = malloc(sizeof(struct SinglyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
}

void FreeList(SinglyLinkedList* list) {
    Node* current = list->head;
    while (current) {
        Node* node = current;
        current = current->next;
        FreeNode(node);
    }
}

// """ Iterate through the list. """
void Travel(SinglyLinkedList* list, void (*travel)(ItemType)) {
    Node* current = list->head;
    while (current) {
        travel(current->data);
        current = current->next;
    }
}

// """ Append an item to the list """
void Append(SinglyLinkedList* list, ItemType data) {
    Node* node = NewNode(data);
    if (list->tail) {
        list->tail->next = node;
        list->tail = node;
    } else {
        list->head = node;
        list->tail = node;
    }
    list->count += 1;
}

// """ Delete a node from the list """
void Delete(SinglyLinkedList* list, ItemType);

// """ Search through the list. Return True if data is found, otherwise
// False. """
bool Search(SinglyLinkedList*, ItemType);

ItemType GetItem(SinglyLinkedList*, int index);
void SetItem(SinglyLinkedList*, int index, ItemType);

