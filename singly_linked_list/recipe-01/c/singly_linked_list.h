#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

// """ A singly-linked node. """
typedef struct Node {
    struct Node* next;
    ItemType data;
} Node;

static Node* DefaultNewNode(ItemType data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    return node;
}

static void DefaultFreeNode(Node* node) {
    free(node);
}

static bool DefaultIsEqual(ItemType a, ItemType b) {
    return a == b;
}

static void DefaultSetItem(Node* node, ItemType data) {
    node->data = data;
}

void (*FreeNode)(Node*) = &DefaultFreeNode;
Node* (*NewNode)(ItemType) = &DefaultNewNode;
bool (*IsEqual)(ItemType, ItemType) = &DefaultIsEqual;
void (*SetItem)(Node* node, ItemType) = &DefaultSetItem;

// """ A singly-linked list. """
typedef struct SinglyLinkedList {
    Node* head;
    Node* tail;
    int count;
} SinglyLinkedList;

// """ Create an empty list. """
static SinglyLinkedList* NewList() {
    SinglyLinkedList* list = malloc(sizeof(struct SinglyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

static void FreeList(SinglyLinkedList* list) {
    Node* current = list->head;
    while (current) {
        Node* node = current;
        current = current->next;
        FreeNode(node);
    }
    free(list);
}

// """ Iterate through the list. """
static void ListTravel(SinglyLinkedList* list, void (*travel)(ItemType)) {
    Node* current = list->head;
    while (current) {
        travel(current->data);
        current = current->next;
    }
}

// """ Append an item to the list """
static void ListAppend(SinglyLinkedList* list, ItemType data) {
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
static void ListDelete(SinglyLinkedList* list, ItemType data) {
    Node* current = list->head;
    Node* prev = list->head;
    while (current) {
        if (IsEqual(current->data, data)) {
            if (current == list->head) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            FreeNode(current);
            list->count -= 1;
        } else {
            prev = current;
        }
        current = prev->next;
    }
}

// """ Search through the list. Return True if data is found, otherwise
// False. """
static bool ListSearch(SinglyLinkedList* list, ItemType data) {
    Node* current = list->head;
    while (current) {
        if (IsEqual(current->data, data)) {
            return true;
        }
        current = current->next;
    }
    return false;
}

static ItemType ListGetItem(SinglyLinkedList* list, int index) {
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

static void ListSetItem(SinglyLinkedList* list, int index, ItemType data) {
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

static int ListCount(SinglyLinkedList* list) {
    return list->count;
}

// """ Reverse the links of the list """
static void ListReverse(SinglyLinkedList* list) {
    Node* next;
    Node* current = list->head;
    Node* prev = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // swap head and tail
    Node* tmp = list->head;
    list->head = list->tail;
    list->tail = tmp;
}



