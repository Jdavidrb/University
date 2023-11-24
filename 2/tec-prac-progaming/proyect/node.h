#ifndef __NODE_H
#define __NODE_H

#include <stdio.h>
#include <stdlib.h>
#include "card.h"

typedef struct Node {
    Card data;
    struct Node* next;
    struct Node* prev;
} Node;


Node* createDeck();
void printDeck(Node* deck);

/* Constructoras */
Node* createNode(Card data);

/* Modificadoras */
Node* insertAtEnd(Node* head, Card data);

void deleteNode(Node** head, Node* del);

/* Analizadoras */
void display(Node* head);

#endif
