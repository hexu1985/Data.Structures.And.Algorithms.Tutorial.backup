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
    node->next = NULL;
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

// """ A singly-linked list. """
typedef struct SinglyLinkedList {
    Node dummy;
    Node* head;
    Node* tail;
    int count;
} SinglyLinkedList;

// """ Create an empty list. """
static SinglyLinkedList* NewList() {
    SinglyLinkedList* list = malloc(sizeof(struct SinglyLinkedList));
    list->head = &list->dummy;
    list->head->next = NULL;
    list->tail = list->head;
    list->count = 0;
    return list;
}

static void FreeList(SinglyLinkedList* list) {
    Node* current = list->head->next;
    while (current) {
        Node* node = current;
        current = current->next;
        FreeNode(node);
    }
    free(list);
}

// """ Iterate through the list. """
static void ListTravel(SinglyLinkedList* list, void (*VisitItem)(ItemType)) {
    Node* current = list->head->next;
    while (current) {
        VisitItem(current->data);
        current = current->next;
    }
}

// """ Append an item to the list """
static void ListAppend(SinglyLinkedList* list, ItemType data) {
    Node* node = NewNode(data);
    list->tail->next = node;
    list->tail = node;
    list->count += 1;
}

// """ Delete a node from the list """
static void ListDelete(SinglyLinkedList* list, ItemType data) {
    Node* current = list->head->next;
    Node* prev = list->head;
    while (current) {
        if (ItemEqual(current->data, data)) {
            prev->next = current->next;
            if (current == list->tail) {
                list->tail = prev;
            }
            FreeNode(current);
            list->count -= 1;
            return;
        } 
        prev = current;
        current = current->next;
    }
}

// """ Search through the list. Return True if data is found, otherwise
// False. """
static bool ListSearch(SinglyLinkedList* list, ItemType data) {
    Node* current = list->head->next;
    while (current) {
        if (ItemEqual(current->data, data)) {
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

    Node* current = list->head->next;
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

    Node* current = list->head->next;
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
    Node* current = list->head->next;   // 指向头Node: current可能为空
    list->head->next = NULL;                        // 重置list头
    list->tail = current ? current : list->head;    // 记录list尾
    while (current) {                   // 遍历list
        Node* next = current->next;

        // 在list表头插入Node
        current->next = list->head->next;
        list->head->next = current;

        current = next;
    }
}

// """ Sort the list """
void ListSort(SinglyLinkedList* list) {
    Node* current = list->head->next;   // 指向头Node: current可能为空
    list->head->next = NULL;            // 重置list头
    list->tail = list->head;            // 重置list尾

    while (current) {                   // 遍历list
        Node* next = current->next;

        // insert the node into output_list and keep sorted
        Node* output_current = list->head->next;
        Node* output_prev = list->head;
        while (output_current) {
            if (ItemLess(current->data, output_current->data))
                break;
            output_prev = output_current;
            output_current = output_current->next;
        }
        current->next = output_current;
        output_prev->next = current;
        if (current->next == NULL) {    // 更新list尾
            list->tail = current;
        }

        current = next;
    }
}


