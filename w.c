//
//  word.c
//  플밍2 플젝
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
void sortList(List *lp)
{
    Node *curp;
    Node *nextp;
    char temp[15];
    if (lp == NULL) { /* lp포인터 NULL check */
        return;
    }
    
    curp = lp->head->next;
    while (curp->next != lp->tail) {
        nextp = curp->next;
        while (nextp != lp->tail) {
            if (strcmp(curp->eng, nextp->eng)) {
                strcpy(temp, curp->eng);
                strcpy(curp->eng, nextp->eng);
                strcpy(nextp->eng, temp);
            }
            nextp = nextp->next;
        }
        curp = curp->next;
    }
}
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

int separateString(char input[], char **sArr, char *std){
//    Node temp = {NULL, "", "", "", "", NULL}; // 여기에 임시적으로 저장하고 후에 lp진퉁에 add해줘야함
//    char input[300]; //임시로 입력받을 긴 문자열하나
//    char *sArr[4] = {NULL, }; // 자른 문자열 포인터 저장할 배열 4칸(최대치를 위해)
    memset(sArr, 0, sizeof(sArr)+1);
    int pmove = 0; // 자른 문자열 포인터 옮겨줄 변수
    char *tokptr = strtok(input, std); // 문자열 공백마다 분리
    while (tokptr != NULL) { // 옮겨주면서 분리한거 저장
        sArr[pmove] = tokptr;
        pmove++;
        tokptr = strtok(NULL, std);
    }
    return pmove;
}


void wordMemCpy(int pmove, char *sArr[], List *lp){
    Node temp = {NULL, "", "", "", "", NULL}; // 여기에 임시적으로 저장하고 후에 lp진퉁에 add해줘야함
    switch (pmove) {
        case 2: // 한글 뜻 한개적었을때
            strcpy(temp.eng, sArr[0]);
                            printf("eng : %s\n", sArr[0]);
            strcpy(temp.kr1, sArr[1]);
                            printf("kor1 : %s\n", sArr[1]);
            addLast(lp, temp.eng, temp.kr1, temp.kr2, temp.kr3);
            break;
        case 3: // 뜻 두개
            strcpy(temp.eng, sArr[0]);
                            printf("eng : %s\n", sArr[0]);
            strcpy(temp.kr1, sArr[1]);
                            printf("kor1 : %s\n", sArr[1]);
            strcpy(temp.kr2, sArr[2]);
                            printf("kor2 : %s\n", sArr[2]);
            addLast(lp, temp.eng, temp.kr1, temp.kr2, temp.kr3);
            break;
        case 4: // 뜻 세개
            strcpy(temp.eng, sArr[0]);
                            printf("eng : %s\n", sArr[0]);
            strcpy(temp.kr1, sArr[1]);
                            printf("kor1 : %s\n", sArr[1]);
            strcpy(temp.kr2, sArr[2]);
                            printf("kor2 : %s\n", sArr[2]);
            strcpy(temp.kr3, sArr[3]);
                            printf("kor3 : %s\n", sArr[3]);
            addLast(lp, temp.eng, temp.kr1, temp.kr2, temp.kr3);
            break;
        default:
            break;
    }
}

