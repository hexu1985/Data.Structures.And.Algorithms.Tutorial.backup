#pragma once

typedef char* ItemType;

#include "doubly_linked_list.h"
#include <string.h>
#include <stdio.h>

#define MAXLINE 128

static Node* NewStringNode(ItemType data) {
    Node* node = malloc(sizeof(Node));
    node->data = malloc(MAXLINE);
    memset(node->data, 0, MAXLINE);
    strncpy(node->data, data, MAXLINE-1);
    return node;
}

static void FreeStringNode(Node* node) {
    free(node->data);
    free(node);
}

static bool StringEqual(ItemType a, ItemType b) {
    return strcmp(a, b) == 0;
}

static void SetString(Node* node, ItemType data) {
    strncpy(node->data, data, MAXLINE-1);
}

static bool StringLess(ItemType a, ItemType b) {
    return strcmp(a, b) < 0;
}

static void Init() {
    NewNode = &NewStringNode;
    FreeNode = &FreeStringNode;
    ItemEqual = &StringEqual;
    SetItem = &SetString;
    ItemLess = &StringLess;
}

static void PrintItem(ItemType data)
{
    printf("%s\n", data);
}

static void ListPrintFoward(DoublyLinkedList *list) 
{
    ListTravel(list, &PrintItem);
}

static void ListPrintBackward(DoublyLinkedList *list) 
{
    ListReverseTravel(list, &PrintItem);
}
