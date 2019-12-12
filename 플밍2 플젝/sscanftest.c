//
//  sscanftest.c
//  플밍2 플젝
//
//  Created by 채채 on 19/11/2019.
//  Copyright © 2019 chaechae. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    
//    char temp[200];
//    char eng[15], k1[30], k2[30], k3[30];
//    scanf("%[^\n]s", temp);
//   printf("%s\n", temp);
//
//    sscanf(temp, "%s %s %s %s", eng, k1, k2, k3);
//    printf("%s %s %s %s\n", eng, k1, k2, k3);
    
    
//    char filename[10];
//    char i[10];
//    int i = 0;
//    sprintf(filename, "%d", i);
//    printf("%s\n", filename);
//    i++;
//    sprintf(filename, "%d", i);
//    printf("%s\n", filename);
//    strcat(filename, ".dic");
//    printf("%s\n", filename);
//    strcat(i, ".dic");
//    printf("%s\n", i);
//    strcpy(filename, i);
//    printf("%s\n", filename);
    
    
    
    char temp[300];
    char eng[20], kor1[30], kor2[30], kor3[30];
    char *sArr[4] = {NULL, };
    int i = 0;
    fgets(temp, sizeof(temp), stdin);
    int len = strlen(temp);
    temp[len-1] = '\0';
    printf("%s\n", temp);
    char *ptr = strtok(temp, " ");
    while (ptr != NULL) {
        sArr[i] = ptr;
        i++;
        ptr = strtok(NULL, " ");
    }
    for (int i = 0; i < 3; i++)
    {
        if (sArr[i] != NULL)           // 문자열 포인터 배열의 요소가 NULL이 아닐 때만
            printf("print : %s\n", sArr[i]);   // 문자열 포인터 배열에 인덱스로 접근하여 각 문자열 출력
    }
    if (sArr[0] != NULL) {
        strcpy(eng, sArr[0]);
        printf("eng : %s\n", sArr[0]);
        strcpy(kor1, sArr[1]);
        printf("kor1 : %s\n", sArr[1]);
        strcpy(kor2, sArr[2]);
        printf("kor2 : %s\n", sArr[2]);
        strcpy(kor3, sArr[3]);
        printf("kor3 : %s\n", sArr[3]);
    }

    return 0;
}
