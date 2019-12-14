//
//  flashcard.c
//  플밍2 플젝
//
//  Created by 채채 on 19/11/2019.
//  Copyright © 2019 chaechae. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "word.h"

void flashCard(void){
    int sec;
    printf("속도(초) : ");
    scanf("%d", &sec);
    
    int day, way;
    char filename[10];
    long long size; // 혹시 모자랄수도 있으니까
    char *wordBook;
    unsigned long whatByte;
    List list;
    List* lp = &list;
    createList(lp);
    
    printf("파일명(일차) : ");
    scanf("%d", &day);
    sprintf(filename, "%d", day);
    strcat(filename, ".dic");
    //    printf("%s\n", filename);
    FILE * numDotDic = fopen(filename, "r"); //새 파일을 읽기용으로 연다
    if (numDotDic == NULL) {
        printf("%s 읽기 실패\n", filename);
        return;
    }
    
    fseek(numDotDic, 0, SEEK_END);
    size = ftell(numDotDic);
    wordBook = (char *)malloc(size+1*sizeof(char)); // 널문자
    memset(wordBook, 0, size + 1);  // 파일 크기 + 1바이트만큼 메모리를 0으로 초기화
    fseek(numDotDic, 0, SEEK_SET); // 다시 처음으로 돌리기
    whatByte = fread(wordBook, size, 1, numDotDic); // 데이터 읽어옴
    
    const int line = getTotalLine(filename); // 라인수 구하면 15+90+4 = 109 + 1 = [line][110]
    
    char *sArr[line]; // 개행기준분리
    separateString(wordBook, sArr, "\n"); // 된당!
//    for (int i = 0; i<line; i++) { // 확인용
//        printf("%s\n", sArr[i]);
//    }
    char *wordSeperated[4]; // 빈칸기준 분리
    char quizArr[line][4][30];
    memset(quizArr, 0, sizeof(quizArr)+1);
    for (int i = 0; i<line; i++) { // line만큼 돌아야함
        int chrCnt = separateString(sArr[i], wordSeperated, " ");
//        printf("cnt : %d\n", chrCnt);
        //        wordMemCpy(chrCnt, wordSeperated, lp);
        for (int j = 0; j<chrCnt; j++) {
            strcpy(quizArr[i][j], wordSeperated[j]);
            //            printf("띄어쓰기마다 분리 : %s\n", wordSeperated[j]);
        }
    }
    
    printf("출력 방식(알파벳 순서대로 : 1, 무작위 : 2) : ");
    scanf("%d", &way);
    if (way == 1) {
        char tempStr[30];
        for (int i = 0; i<line-1; i++) {
            for (int j = 0; j<line-1-i; j++) {
                if (strcmp(quizArr[j][0], quizArr[j+1][0]) > 0) {
                    stringCpy(tempStr, quizArr, j);
                }
            }
        }
    } else {
        shuffle(quizArr, line);
    }
    
    system("clear");
//    printf(">> 영어 단어 암기 프로그램 : 플래쉬카드 <<\n");
//    printf("\n");
    for (int i = 0; i<line; i++) {
        printf(">> 영어 단어 암기 프로그램 : 플래쉬카드 <<\n\n");
        printf("\t%s\n", quizArr[i][0]);
        sleep(sec);
        system("clear");
        printf(">> 영어 단어 암기 프로그램 : 플래쉬카드 <<\n\n");
        printf("\t%s %s %s\n", quizArr[i][1], quizArr[i][2], quizArr[i][3]);
        sleep(sec);
        system("clear");
        
    }
    system("clear");

}
