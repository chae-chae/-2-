//
//  LL써서 메인.c
//  플밍2 플젝
//
//  Created by 채채 on 19/11/2019.
//  Copyright © 2019 chaechae. All rights reserved.
//

#include <time.h>
#include "word.h"
#include <string.h>

int menuScreen(void);
int input(void);
void MyFlush(void);
//void quiz(void);
//void flashCard(void);
//void hangMan(void);
void wordBook(FILE *);
void addNewFile(FILE *);
void addNewWord(FILE* ddlp);
void viewWordBook(void);
void viewFileList(void);


typedef struct _word{
    char eng[15];
    char kor[30];
    int num;
} Word;
//typedef struct _list{
//    int cnt;
//    Word *wp;
//} List;
//

static int wordBookCnt = 0;

int main(int argc, const char * argv[]) {
    
    FILE * dicDotList = fopen("dic.list", "at"); // dic.list파일(n.dic가 들어갈 파일 생성)
    
//    List list; // 링크드리스트 관리구조체 (아직 데이터노드가 안붙었음)
//    BOOL bres; // 링크드리스트 관리구조체 제대로 만들어졌는지 불값저장
    
    int menusel;
    menusel = menuScreen();
    while (menusel != 5) {
        switch (menusel) {
                //            case 1: quiz(); break;
                //            case 2: flashCard(); break;
                //            case 3: hangMan(); break;
            case 4: wordBook(dicDotList); break;
            default: break;
        }
        menusel = menuScreen();
    }
    //    clear(); // 리눅스에서 해줘야함!! 까먹지말기
    return 0;
}

void MyFlush(void){
    while (getchar() != '\n') {
        ;
    }
}

int menuScreen(void){
    int sel;
    
    printf(">> 영어 단어 암기 프로그램 <<\n");
    printf("1. 영어 단어 맞추기\t2. 플래쉬카드\n");
    printf("3. 행맨(hangman)\t4. 단어장 관리\n");
    printf("5. 프로그램 종료\n\n");
    
    sel = input();
    return sel;
}
int input(void){
    int sel;
    while (1) {
        printf("번호를 입력하세요 : ");
        scanf("%d", &sel);
        if (1<= sel && sel <= 5 && getchar() == '\n') {
            break;
        }
        MyFlush();
    }
    return sel;
}
void wordBook(FILE *ddlp){
    int sel;
    //    clear(); // 리눅스해주기
    
    printf(">> 영어 단어 암기 프로그램 : 단어장 관리 <<\n");
    printf("1. 새 파일 추가하기\t2. 새 단어 추가하기\n");
    printf("3. 단어장 보기\t4. 단어 파일 목록보기\n");
    printf("5. 단어장 관리 종료\n\n");
    
    sel = input();
    while (sel != 5) {
        switch (sel) {
            case 1: addNewFile(ddlp); break; //단어장 만드는 메뉴
            case 2: addNewWord(ddlp); break;
            case 3: viewWordBook(); break;
            case 4: viewFileList(); break;
            default: break;
        }
        printf(">> 영어 단어 암기 프로그램 : 단어장 관리 <<\n");
        printf("1. 새 파일 추가하기\t2. 새 단어 추가하기\n");
        printf("3. 단어장 보기\t4. 단어 파일 목록보기\n");
        printf("5. 단어장 관리 종료\n\n");
        sel = input();
    }
    return;
}
void addNewFile(FILE* ddlp){
    printf(">> 영어 단어 암기 프로그램 : 단어장 관리 : 새 파일 추가 <<\n");
    wordBookCnt++; // 단어장 하나 추가
    char filename[10];
    sprintf(filename, "%d", wordBookCnt);
    strcat(filename, ".dic");
    //    printf("%s\n", filename);
    FILE * numDotDic= fopen(filename, "wt"); //새 파일을 쓰기용으로 연다
    List list;
    List* lp = &list;
    createList(lp); // 링크드리스트 초기화
    int max = 0;
    
    while (max<20) {
        Node temp = {NULL, "", "", "", "", NULL}; // 여기에 임시적으로 저장하고 후에 lp진퉁에 add해줘야함
        char input[300]; //임시로 입력받을 긴 문자열하나
        char *sArr[4] = {NULL, }; // 자른 문자열 포인터 저장할 배열 4칸(최대치를 위해)
        int pmove = 0; // 자른 문자열 포인터 옮겨줄 변수
        
        fgets(input, sizeof(input), stdin); // 공백포함해서 쭉받고 마지막개행까지받아서
        
        unsigned long len = strlen(input);
        input[len-1] = '\0'; // 개행빼주는 작업
//        printf("input : %s\n", input); // 확인
        char *tokptr = strtok(input, " "); // 문자열 공백마다 분리
        while (tokptr != NULL) { // 옮겨주면서 분리한거 저장
            sArr[pmove] = tokptr;
            pmove++;
            tokptr = strtok(NULL, " ");
        }
        
        if (!strcmp(sArr[0], ".add")) {// .add 입력종료조건
            printf(".add로 종료됨\n");
            break;
        }
        
        switch (pmove) {
            case 2: // 한글 뜻 한개적었을때
                strcpy(temp.eng, sArr[0]);
                //                printf("eng : %s\n", sArr[0]);
                strcpy(temp.kr1, sArr[1]);
                //                printf("kor1 : %s\n", sArr[1]);
                addLast(lp, temp.eng, temp.kr1, temp.kr2, temp.kr3);
                break;
            case 3: // 뜻 두개
                strcpy(temp.eng, sArr[0]);
                //                printf("eng : %s\n", sArr[0]);
                strcpy(temp.kr1, sArr[1]);
                //                printf("kor1 : %s\n", sArr[1]);
                strcpy(temp.kr2, sArr[2]);
                //                printf("kor2 : %s\n", sArr[2]);
                addLast(lp, temp.eng, temp.kr1, temp.kr2, temp.kr3);
                break;
            case 4: // 뜻 세개
                strcpy(temp.eng, sArr[0]);
                //                printf("eng : %s\n", sArr[0]);
                strcpy(temp.kr1, sArr[1]);
                //                printf("kor1 : %s\n", sArr[1]);
                strcpy(temp.kr2, sArr[2]);
                //                printf("kor2 : %s\n", sArr[2]);
                strcpy(temp.kr3, sArr[3]);
                //                printf("kor3 : %s\n", sArr[3]);
                addLast(lp, temp.eng, temp.kr1, temp.kr2, temp.kr3);
                break;
            default:
                break;
        }
        max++;
    }
    displayList(lp); // 확인용
    saveList(lp, numDotDic); // n.dic파일 저장
    fprintf(ddlp, "%s ", filename); //dic.list 에 n.dic 이라고 이어서 씀
    fclose(numDotDic); // n.dic 닫아주기
    return;
}
void addNewWord(FILE* ddlp){
    char daySel[20];
    printf("단어를 추가할 단어장을 입력해주세요 (x.dic) : ");
    scanf("%s", daySel);
    FILE *numDotDic = fopen(daySel, "at");
    printf("%s 열기 성공\n", daySel);
    MyFlush();
    List list;
    List* lp = &list;
    createList(lp);
    int max = 0;
    
    while (max<20) {
        char input[300]; //임시로 입력받을 긴 문자열하나
        char *sArr[4] = {NULL, }; // 자른 문자열 포인터 저장할 배열 4칸(최대치를 위해)
        int pmove = 0; // 자른 문자열 포인터 옮겨줄 변수
        Node temp = {NULL, "", "", "", "", NULL}; // 여기에 임시적으로 저장하고 후에 lp진퉁에 add해줘야함
        fgets(input, sizeof(input), stdin); // 공백포함해서 쭉받고 마지막개행까지받아서

        unsigned long len = strlen(input);
        input[len-1] = '\0'; // 개행빼주는 작업
        printf("input : %s\n", input); // 확인
        char *tokptr = strtok(input, " "); // 문자열 공백마다 분리
        while (tokptr != NULL) { // 옮겨주면서 분리한거 저장
            sArr[pmove] = tokptr;
            pmove++;
            tokptr = strtok(NULL, " ");
        }

        if (!strcmp(sArr[0], ".add")) {// .add 입력종료조건
            printf(".add로 종료됨\n");
            break;
        }

        switch (pmove) {
            case 2: // 한글 뜻 한개적었을때
                strcpy(temp.eng, sArr[0]);
                //                printf("eng : %s\n", sArr[0]);
                strcpy(temp.kr1, sArr[1]);
                //                printf("kor1 : %s\n", sArr[1]);
                addLast(lp, temp.eng, temp.kr1, temp.kr2, temp.kr3);
                break;
            case 3: // 뜻 두개
                strcpy(temp.eng, sArr[0]);
                //                printf("eng : %s\n", sArr[0]);
                strcpy(temp.kr1, sArr[1]);
                //                printf("kor1 : %s\n", sArr[1]);
                strcpy(temp.kr2, sArr[2]);
                //                printf("kor2 : %s\n", sArr[2]);
                addLast(lp, temp.eng, temp.kr1, temp.kr2, temp.kr3);
                break;
            case 4: // 뜻 세개
                strcpy(temp.eng, sArr[0]);
                //                printf("eng : %s\n", sArr[0]);
                strcpy(temp.kr1, sArr[1]);
                //                printf("kor1 : %s\n", sArr[1]);
                strcpy(temp.kr2, sArr[2]);
                //                printf("kor2 : %s\n", sArr[2]);
                strcpy(temp.kr3, sArr[3]);
                //                printf("kor3 : %s\n", sArr[3]);
                addLast(lp, temp.eng, temp.kr1, temp.kr2, temp.kr3);
                break;
            default:
                break;
        }
        max++;
    }
    //    displayList(lp); // 확인용
    saveList(lp, numDotDic); // n.dic파일 저장
//    fprintf(ddlp, "%s ", filename); //dic.list 에 n.dic 이라고 이어서 씀
    fclose(numDotDic); // n.dic 닫아주기
}
void viewWordBook(void){
    
}
void viewFileList(void){
    
}


