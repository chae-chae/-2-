//
//  word.h
//  플밍2 플젝
//
//  Created by 채채 on 19/11/2019.
//  Copyright © 2019 chaechae. All rights reserved.
//

#ifndef word_h
#define word_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

enum _bool{FALSE, TRUE};
typedef enum _bool BOOL;
typedef struct _node Node;
struct _node{
    Node *prev;
    char eng[16];
    char kr1[61], kr2[61], kr3[61];
    Node *next;
};
typedef struct _list{
    Node *head;
    Node *tail;
    int size;
}List;

BOOL createList(List *lp);                    /* 연결 리스트 초기화 */
BOOL addLast(List *lp, char eng[], char k1[], char k2[], char k3[]);            /* tail node 앞에 node 추가(정순 저장) */
void displayList(List *lp);                    /* 리스트 내의 모든 데이터 출력 */
void saveList(List *lp, FILE *fp); // file에 저장
void destroyList(List *lp);                    /* 리스트 내의 모든 노드를 삭제 */
int separateString(char input[], char **sArr, char *std);
void shuffle(char string[][4][61], int num);
void stringCpy(char temp[], char string[][4][61], int index);
int getTotalLine(char *name);
void MyFlush(void);
#endif /* word_h */

