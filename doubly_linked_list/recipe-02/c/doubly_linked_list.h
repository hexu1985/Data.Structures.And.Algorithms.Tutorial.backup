#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

// """ A Doubly-linked lists' node. """
typedef struct Node {
    struct Node* next;
    struct Node* prev;
    ItemType data;
} Node;

static Node* DefaultNewNode(ItemType data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = node->prev = NULL;
    return node;
}

static void DefaultFreeNode(Node* node) {
    free(node);
}

static bool DefaultItemEqual(ItemType a, ItemType b) {
    return a == b;
}

static void DefaultSetItem(Node* node, ItemType data) {
    node->data = data;
}

static bool DefaultItemLess(ItemType a, ItemType b) {
    return a < b;
}

void (*FreeNode)(Node*) = &DefaultFreeNode;
Node* (*NewNode)(ItemType) = &DefaultNewNode;
bool (*ItemEqual)(ItemType, ItemType) = &DefaultItemEqual;
void (*SetItem)(Node* node, ItemType) = &DefaultSetItem;
bool (*ItemLess)(ItemType, ItemType) = &DefaultItemLess;

typedef struct DoublyLinkedList {
    Node dummy;
    Node* nil;
    int count;
} DoublyLinkedList;


// """ Create an empty list. """
static DoublyLinkedList* NewList() {
    DoublyLinkedList* list = malloc(sizeof(struct DoublyLinkedList));
    list->nil = &list->dummy;
    list->nil->next = list->nil->prev = list->nil;
    list->count = 0;
    return list;
}

static void FreeList(DoublyLinkedList* list) {
    Node* current = list->nil->next;
    while (current != list->nil) {
        Node* node = current;
        current = current->next;
        FreeNode(node);
    }
    free(list);
}

// """ Iterate through the list. """
static void ListTravel(DoublyLinkedList* list, void (*VisitItem)(ItemType)) {
    Node* current = list->nil->next;
    while (current != list->nil) {
        VisitItem(current->data);
        current = current->next;
    }
}

// """ Iterate backwards through the list. """
static void ListReverseTravel(DoublyLinkedList* list, void (*VisitItem)(ItemType)) {
    Node* current = list->nil->prev;
    while (current != list->nil) {
        VisitItem(current->data);
        current = current->prev;
    }
}

// """ Append an item to the list """
static void ListAppend(DoublyLinkedList* list, ItemType data) {
    Node* node = NewNode(data);
    // insert before nil.
    Node* current = list->nil;
    Node* prev_node = current->prev;

    node->prev = prev_node;
    node->next = current;

    prev_node->next = node;
    current->prev = node;

    list->count += 1;
}

// """ Delete a node from the list """
static bool ListDelete(DoublyLinkedList* list, ItemType data) {
    Node* current = list->nil->next;
    while (current != list->nil) {
        if (ItemEqual(current->data, data)) {
            Node* prev_node = current->prev;
            Node* succ_node = current->next;

            prev_node->next = succ_node;
            succ_node->prev = prev_node;

            FreeNode(current);
            list->count -= 1;
            return true;
        }
        current = current->next;
    }
    return false;
}

// """Search through the list. Return True if data is found, otherwise False."""
static bool ListSearch(DoublyLinkedList* list, ItemType data) {
    Node* current = list->nil->next;
    while (current != list->nil) {
        if (ItemEqual(current->data, data)) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// """ Insert new node at the head of linked list. """
static void ListInsertHead(DoublyLinkedList* list, ItemType data) {
    Node* node = NewNode(data);
    // insert before nil->next.
    Node* current = list->nil->next;
    Node* prev_node = current->prev;

    node->prev = prev_node;
    node->next = current;

    prev_node->next = node;
    current->prev = node;
        
    list->count += 1;
}

static ItemType ListGetItem(DoublyLinkedList* list, int index) {
    if (index > list->count - 1) {
        fprintf(stderr, "Index out of range.");
        exit(1);
    }

    Node* current = list->nil->next;
    for (int n = 0; n < index; n++) {
        current = current->next;
    }
    return current->data;
}

static void ListSetItem(DoublyLinkedList* list, int index, ItemType data) {
    if (index > list->count - 1) {
        fprintf(stderr, "Index out of range.");
        exit(1);
    }

    Node* current = list->nil->next;
    for (int n = 0; n < index; n++) {
        current = current->next;
    }
    SetItem(current, data);
}

static int ListCount(DoublyLinkedList* list) {
    return list->count;
}

// """ Reverse the links of the list """
static void ListReverse(DoublyLinkedList* list) {
    Node* current = list->nil->next;
    Node* tmp;
    while (current != list->nil) {
        tmp = current->next;
        current->next = current->prev;
        current->prev = tmp;
        current = current->prev;
    }

    // Now reverse the order of head and tail
    tmp = list->nil->next;
    list->nil->next = list->nil->prev;
    list->nil->prev = tmp;
}

