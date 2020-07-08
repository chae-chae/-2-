//
//  hangman.c
//  플밍2 플젝
//
//  Created by 채채 on 19/11/2019.
//  Copyright © 2019 chaechae. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "word.h"

void hangMan(void){
    printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");
    int day;
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
    const int line = getTotalLine(filename);
    char *sArr[line]; // 개행기준분리
    separateString(wordBook, sArr, "\n"); // 된당!
    char *wordSeperated[4]; // 빈칸기준 분리
    char quizArr[line][4][61];
    memset(quizArr, 0, sizeof(quizArr)+1);
    for (int i = 0; i<line; i++) { // line만큼 돌아야함
        int chrCnt = separateString(sArr[i], wordSeperated, " ");
        for (int j = 0; j<chrCnt; j++) {
            strcpy(quizArr[i][j], wordSeperated[j]);
        }
    }
    int rn = rand() % line;
    int len = strlen(quizArr[rn][0]); // 단어 길이
    char answer[len+1];
    int try = 1;
    int man = 0;
    char input;
    system("clear");
    printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");
    printf("(힌트) %s %s %s\n\n",  quizArr[rn][1], quizArr[rn][2], quizArr[rn][3]);
    printf("----------+\n");
    printf("\n\n\n");
    for (int i = 0; i<len; i++) {
        answer[i] = '_';
    }
    answer[len] = '\0';
    while (man<6) {
        printf("%s\n\n", answer);
        printf("%d 번째 시도 : ", try);
        MyFlush();
        scanf("%c", &input);
        try++;
        if (strchr(quizArr[rn][0], input) != NULL) { // 정답이라면
            for (int i = 0; i<len; i++) {
                if (quizArr[rn][0][i] == input) {
                    answer[i] = input;
                }
            }
        } else { // 틀리면 맨++
            man++;
        }
        switch (man) {
            case 1:
                system("clear");
                printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");
                printf("(힌트) %s %s %s\n\n",  quizArr[rn][1], quizArr[rn][2], quizArr[rn][3]);
                printf("----------+\n");
                printf("          O\n");
                break;
            case 2:
                system("clear");
                printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");
                printf("(힌트) %s %s %s\n\n",  quizArr[rn][1], quizArr[rn][2], quizArr[rn][3]);
                printf("----------+\n");
                printf("          O\n");
                printf("          |\n");
                break;
            case 3:
                system("clear");
                printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");
                printf("(힌트) %s %s %s\n\n",  quizArr[rn][1], quizArr[rn][2], quizArr[rn][3]);
                printf("----------+\n");
                printf("          O\n");
                printf("         /|\n");
                break;
            case 4:
                system("clear");
                printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");
                printf("(힌트) %s %s %s\n\n",  quizArr[rn][1], quizArr[rn][2], quizArr[rn][3]);
                printf("----------+\n");
                printf("          O\n");
                printf("         /|\\\n");
                break;
            case 5:
                system("clear");
                printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");
                printf("(힌트) %s %s %s\n\n",  quizArr[rn][1], quizArr[rn][2], quizArr[rn][3]);
                printf("----------+\n");
                printf("          O\n");
                printf("         /|\\\n");
                printf("         /\n");
                break;
            case 6:
                system("clear");
                printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");
                printf("(힌트) %s %s %s\n\n",  quizArr[rn][1], quizArr[rn][2], quizArr[rn][3]);
                printf("----------+\n");
                printf("          O\n");
                printf("         /|\\\n");
                printf("         /\\\n");
                break;
            default:
                system("clear");
                printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");
                printf("(힌트) %s %s %s\n\n",  quizArr[rn][1], quizArr[rn][2], quizArr[rn][3]);
                printf("----------+\n");
                break;
        }
        if (strcmp(quizArr[rn][0], answer) == 0) { //quizArr랑 답이랑 같으면 - 다맞추면
            printf("\n\n\n%s\n\n", answer);
            printf("%d 번째 시도 : %c\n", try-1, input);
            printf("\n\n\n######################\n");
            printf("###Congratulations!###\n");
            printf("######################\n");
            sleep(3);
            system("clear");
            return;
        }
        printf("\n\n\n");
    }
    printf("\n\n\n##############\n");
    printf("#####Fail#####\n");
    printf("##############\n");
    sleep(3);
    system("clear");
    destroyList(lp);
    free(wordBook);
}
