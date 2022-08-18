#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

// """ A singly-linked node. """
struct Node {
    Node* next;
    ItemType data;
};

// provide by user
Node* NewNode(ItemType);
void FreeNode(Node*);
bool IsItemEqual(ItemType, ItemType);

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

static void FreeList(SinglyLinkedList* list) {
    Node* current = list->head;
    while (current) {
        Node* node = current;
        current = current->next;
        FreeNode(node);
    }
}

// """ Iterate through the list. """
static void Travel(SinglyLinkedList* list, void (*travel)(ItemType)) {
    Node* current = list->head;
    while (current) {
        travel(current->data);
        current = current->next;
    }
}

// """ Append an item to the list """
static void Append(SinglyLinkedList* list, ItemType data) {
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
static void Delete(SinglyLinkedList* list, ItemType data) {
    Node* current = list->head;
    Node* prev = list->head;
    while (current) {
        if (IsItemEqual(current->data, data)) {
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
static bool Search(SinglyLinkedList* list, ItemType data) {
    Node* current = list->head;
    while (current) {
        if (IsItemEqual(current->data, data)) {
            return true;
        }
        current = current->next;
    }
    return false;
}

static ItemType GetItem(SinglyLinkedList* list, int index) {
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

static void SetItem(SinglyLinkedList* list, int index, ItemType data) {
    if (index > list->count - 1) {
        fprintf(stderr, "Index out of range.");
        exit(1);
    }

    Node* current = list->head;
    for (int n = 0; n < index; n++) {
        current = current->next;
    }
    current->data = data;
}

