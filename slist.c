#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "slist.h"

#define ROW 6
#define COL 7

SList* createList() {
    SList* list = (SList*)malloc(sizeof(SList));
    list->head = NULL;
    return list;
}

void insertNode(SList* list, int column, char player) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->column = column;
    newNode->player = player;
    newNode->next = NULL;
    
    if(!list->head) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void replay(SList* list, char (*tempBoard)[7]) {
    if(!list) return;
    Node* temp = list->head;
    while(temp) {
        // Apply the moves
        for (int i = ROW - 1; i >= 0; i--) {
            if (tempBoard[i][temp->column] == ' ') {
                tempBoard[i][temp->column] = temp->player;
                break;
            }
        }
        
        // Print tempBoard
        for (int i = 0; i < ROW; i++) {
            printf("|");
            for (int j = 0; j < COL; j++) {
                printf("%c|", tempBoard[i][j]);
            }
            printf("\n");
        }
        printf("---------------\n");
        
        temp = temp->next;
        sleep(1);
    }   
}



void freeList(SList* list) {
    Node* temp;
    while(list->head) {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    free(list);
}
