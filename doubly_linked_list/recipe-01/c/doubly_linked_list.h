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
    Node* head;
    Node* tail;
    int count;
} DoublyLinkedList;


// """ Create an empty list. """
static DoublyLinkedList* NewList() {
    DoublyLinkedList* list = malloc(sizeof(struct DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

static void FreeList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current) {
        Node* node = current;
        current = current->next;
        FreeNode(node);
    }
    free(list);
}

// """ Iterate through the list. """
static void ListTravel(DoublyLinkedList* list, void (*VisitItem)(ItemType)) {
    Node* current = list->head;
    while (current) {
        VisitItem(current->data);
        current = current->next;
    }
}

// """ Iterate backwards through the list. """
static void ListReverseTravel(DoublyLinkedList* list, void (*VisitItem)(ItemType)) {
    Node* current = list->tail;
    while (current) {
        VisitItem(current->data);
        current = current->prev;
    }
}

// """ Append an item to the list """
static void ListAppend(DoublyLinkedList* list, ItemType data) {
    Node* node = NewNode(data);
    if (list->head) {   // list not empty
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    } else {
        list->tail = list->head = node;
    }
    list->count += 1;
}

// """ Delete a node from the list """
static void ListDelete(DoublyLinkedList* list, ItemType data) {
    Node* current = list->head;
    while (current) {
        if (ItemEqual(current->data, data)) {
            if (current->prev) {    // current is not head node
                current->prev->next = current->next;
            } else {
                if (current->next) current->next->prev = NULL;
                list->head = current->next;
            }
            if (current->next) {    // current is not tail node
                current->next->prev = current->prev;
            } else {
                if (current->prev) current->prev->next = NULL;
                list->tail = current->prev;
            }
            FreeNode(current);
            list->count -= 1;
            return;
        }
        current = current->next;
    }
}

// """Search through the list. Return True if data is found, otherwise False."""
static bool ListSearch(DoublyLinkedList* list, ItemType data) {
    Node* current = list->head;
    while (current) {
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
    if (list->head) {   // list not empty
        list->head->prev = node;
        node->next = list->head;
        list->head = node;
    } else {
        list->tail = list->head = node;
    }
    list->count += 1;
}

static ItemType ListGetItem(DoublyLinkedList* list, int index) {
    if (index > list->count - 1) {
        fprintf(stderr, "Index out of range.");
        exit(1);
    }

    Node* current = list->head;
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

    Node* current = list->head;
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
    Node* current = list->head;
    Node* tmp;
    while (current) {
        tmp = current->next;
        current->next = current->prev;
        current->prev = tmp;
        current = current->prev;
    }

    // Now reverse the order of head and tail
    tmp = list->head;
    list->head = list->tail;
    list->tail = tmp;
}

