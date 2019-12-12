//
//  quiz.c
//  플밍2 플젝
//
//  Created by 채채 on 19/11/2019.
//  Copyright © 2019 chaechae. All rights reserved.
//

#include <stdio.h>

void quiz(void){
    int day, way;
    printf("파일명(일차) : ");
    scanf("%d", &day);
    //day.dic 읽어오기
    printf("출력 방식(알파벳 순서대로 : 1, 무작위 : 2) : ");
    scanf("%d", &way);
    if (way == 1) {
        //알파벳 순 소트
    } else {
        //random()소트
    }
    return;
}
