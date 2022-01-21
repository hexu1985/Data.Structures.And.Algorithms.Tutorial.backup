#ifndef LIST_H
#define LIST_H

typedef struct Node* Link;

typedef int ItemType;

struct Node
{
	ItemType item;
	Link next;
};

void InitNodes(int);
Link NewNode(ItemType);
void FreeNode(Link);

void InsertNext(Link, Link);
Link DeleteNext(Link);

Link Next(Link);
int Item(Link);

#endif
