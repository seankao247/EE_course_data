#include <stdio.h>
#include <stdlib.h>
//此打法為賴書拓的打法
typedef struct model
{
    int number;
    char name[20];
    struct model* next;
}model;//創立一結構
int main()
{
    int N,count=0;
    model* a,* first,* later;
    for(;;)/*1.表示首次2.表示第二次或以上*/
    {
        printf("請輸入數字 : ");
        scanf("%d",&N);//讀數字
        if(N==0)break;//輸入0就跳出去
        a=(model* )malloc(sizeof(model));//1.跟記憶體要一個model大小的結構(a指向這個結構)2.a指向新結構,舊的斷掉
        a->number=N;
        printf("請輸入名字 : ");
        scanf("%s",a->name);
        if(count==0) first=a;//如果a指向第一個結構,則first也指向這第一個結構
        else later->next=a;//原本指向NULL變成指向下一個結構(a)
        a->next=NULL;//預設a指向的結構裡面的指標是空指標
        later=a;//1.later也指向目前a指向的指標,因為待會迴圈時a指標會指向別處2.前一個結構的next已經和下一個連起來了
        count++;                                                                                           //所以later指向下一個結構,和上一個結構切掉
    }
    a=first;
    printf("\n順序 : ");
    while(a!=NULL)
    {
        printf("(%d,%s)-->",a->number,a->name);
        a=a->next;
    }
    printf("THE END");
    return 0;
}
