//
//  word.c
//  플밍2 플젝
//
//  Created by 채채 on 19/11/2019.
//  Copyright © 2019 chaechae. All rights reserved.
//

#include "word.h"

BOOL createList(List *lp){
    if (lp == NULL) {
        return FALSE;
    }
    lp->head = (Node *)malloc(sizeof(Node));
    if (lp->head == NULL) {
        return FALSE;
    }
    lp->tail = (Node *)malloc(sizeof(Node));
    if (lp->tail == NULL) {
        free(lp->head);
        return FALSE;
    }
    lp->head->next = lp->tail;
    lp->tail->next = lp->tail;
    lp->head->prev = lp->head;
    lp->tail->prev = lp->head;
    lp->size = 0;
    
    return TRUE;
}
BOOL addLast(List *lp, char eng[], char k1[], char k2[], char k3[]){
    Node *np;
    if (lp == NULL) {
        return FALSE;
    }
    np = (Node *)malloc(sizeof(Node));
    if (np != NULL) {
        strcpy(np->eng, eng);
        strcpy(np->kr1, k1);
        strcpy(np->kr2, k2);
        strcpy(np->kr3, k3);
        np->next = lp->tail;
        np->prev = lp->tail->prev;
        np->prev->next = np;
        lp->tail->prev = np;
        ++lp->size;
        return TRUE;
    } else {
        return FALSE;
    }
}
void displayList(List *lp){
    Node *cp;
    if (lp == NULL) { /* lp포인터 NULL check */
        return;
    }
    cp = lp->head->next;
    printf("---------단어장----------\n");
    while (cp != lp->tail) {
        printf("%s %s %s %s\n", cp->eng, cp->kr1, cp->kr2, cp->kr3);
        cp = cp->next;
    }
    return;
}
//BOOL removeNode(List *lp, int data){
//
//}
//Node * searchNode(List *lp, int data);        /* data와 일치하는 node 검색 */
//void sortList(List *lp){
//
//}                    /* 노드 정렬 - 오름차순 */
void destroyList(List *lp){
    Node *cp;
    Node *nextp;
    if (lp == NULL) {
        return;
    }
    cp = lp->head->next;
    while (cp != lp->tail) {
        nextp = cp->next;
        free(cp);
        cp = nextp;
    }
    free(lp->head);
    free(lp->tail);
    
    lp->head = lp->tail = NULL;
    lp->size = 0;
    return;
}
void saveList(List *lp, FILE *fp){
    Node *cp;
    if (lp == NULL) { /* lp포인터 NULL check */
        return;
    }
    cp = lp->head->next;
    while (cp != lp->tail) {
        fprintf(fp, "%s %s %s %s\n", cp->eng, cp->kr1, cp->kr2, cp->kr3);
        cp = cp->next;
    }
    return;
}
