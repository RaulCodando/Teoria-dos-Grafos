#include "LinkedList.h"

Node *createLinkedList(){
    return NULL;
}

Node *addNodeEnd(Node *head, int item){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->item = item;
    
    if(head == NULL){
        newNode->next = head;
        return newNode;
    }

    Node *aux = head;

    while(aux->next != NULL){
        aux = aux->next;
    }

    newNode->next = aux->next;
    aux->next = newNode;

    return head;
}

Node *addNodeStart(Node *head, int item){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = head;
    return newNode;
}

void clearList(Node *head){
    while(head != NULL){
        Node *aux = head;
        head = head->next;
        free(aux);
    }
}
