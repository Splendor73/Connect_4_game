#ifndef SLIST_H
#define SLIST_H

typedef struct Node {
    int column; 
    char player;
    struct Node* next;
} Node;

typedef struct SList {
    Node* head;
} SList;

SList* createList();
void insertNode(SList* list, int column, char player);
void replay(SList* list, char (*tempBoard)[7]);
void freeList(SList* list);

#endif
