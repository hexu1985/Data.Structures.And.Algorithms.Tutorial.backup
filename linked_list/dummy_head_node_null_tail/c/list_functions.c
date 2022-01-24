#include "list.h"
#include <stdlib.h>
#include <assert.h>

void InitNodes(int N)
{}

Link NewNode(ItemType i)
{
    Link l = (Link) malloc(sizeof(struct Node));
    l->item = i;
    l->next = NULL;
    return l;
}

void FreeNode(Link link)
{
    free(link);
}

void InsertNext(Link l1, Link l2)
{
    assert(l1 && l2);
    l2->next = l1->next;
    l1->next = l2;
}

Link DeleteNext(Link l)
{
    assert(l);
    Link t = l->next;
    if (t) l->next = t->next;
    return t;
}

Link Next(Link l)
{
    assert(l);
    return l->next;
}

ItemType Item(Link l)
{
    assert(l);
    return l->item;
}
