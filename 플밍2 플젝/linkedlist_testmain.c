//
//  linkedlist_testmain.c
//  플밍2 플젝
//
//  Created by 채채 on 19/11/2019.
//  Copyright © 2019 chaechae. All rights reserved.
//

//#include <stdio.h>
#include "word.h"

int main(void){
    BOOL bres;
    List list;
    
    bres = createList(&list);
    if (bres == TRUE)
        printf("@ list 생성 성공!\n");
    else
        printf("@ list 생성 실패!\n");

    char temp[200];
        char eng[15], k1[30], k2[30], k3[30];
        scanf("%[^\n]s", temp);
    //    printf("%s\n", temp);
        
        sscanf(temp, "%s %s %s %s", eng, k1, k2, k3);
//        printf("%s %s %s %s\n", eng, k1, k2, k3);
    addLast(&list, eng, k1, k2, k3);
    displayList(&list);

    printf("list내의 데이터 노드의 개수 : %d\n", list.size);
    destroyList(&list);
    return 0;
}
