#pragma once

typedef char* ItemType;

#include "singly_linked_list.h"
#include <string.h>

#define MAXLINE 128

Node* NewNode(ItemType data) {
    Node* node = malloc(sizeof(Node));
    node->data = malloc(MAXLINE);
    memset(node->data, 0, MAXLINE);
    strncpy(node->data, data, MAXLINE-1);
    return node;
}

void FreeNode(Node* node) {
    free(node->data);
    free(node);
}

bool IsEqual(ItemType a, ItemType b) {
    return strcmp(a, b) == 0;
}

void SetData(Node* node, ItemType data) {
    strncpy(node->data, data, MAXLINE-1);
}

bool IsLess(ItemType a, ItemType b) {
    return strcmp(a, b) < 0;
}
