#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int item;
    struct node *next;
}Node;

Node *createLinkedList();

Node *addNodeEnd(Node *head, int item);

Node *addNodeStart(Node *head, int item);

void clearList(Node *head);

#endif //LINKEDLIST_H
