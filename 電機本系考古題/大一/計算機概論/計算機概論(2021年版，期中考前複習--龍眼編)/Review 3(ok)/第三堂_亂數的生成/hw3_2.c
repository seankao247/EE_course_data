#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int lottery,input;
    int ln[4],mn[4];

    srand(time(NULL));
    //語法=(rand()%幾個數)+從哪個數開始
    lottery=(rand()%9000)+1000;
    printf("The number is:%d\n",lottery);
    printf("your number:");
    scanf("%d",&input);

    printf("樂透號碼:%d\n",lottery);
    printf("輸入號碼:%d\n",input);

    if(lottery==input)
        printf("恭喜中大獎\n");
    else{    //2916
    ln[3]=lottery/1000;             //2
    ln[2]=(lottery%1000)/100;       //9
    ln[1]=(lottery%100)/10;         //1
    ln[0]=lottery%10;               //6

    mn[3]=input/1000;             //2
    mn[2]=(input%1000)/100;       //9
    mn[1]=(input%100)/10;         //1
    mn[0]=input%10;

        if((ln[3]==mn[3] && ln[2]==mn[2] && ln[1]==mn[1] && ln[0]!=mn[0] )||(ln[3]==mn[3] && ln[2]==mn[2] && ln[0]==mn[0] && ln[1]!=mn[1] )||
           (ln[3]==mn[3] && ln[1]==mn[1] && ln[0]==mn[0] && ln[2]!=mn[2] )||(ln[0]==mn[0] && ln[2]==mn[2] && ln[1]==mn[1] && ln[3]!=mn[3] ) )
        printf("恭喜中貳獎\n");
        else if(mn[3]!=ln[3] && mn[3]!=ln[2] && mn[3]!=ln[1] &&mn[3]!=ln[0]&&mn[2]!=ln[3] && mn[2]!=ln[2] && mn[2]!=ln[1] &&mn[2]!=ln[0]&&mn[1]!=ln[3] &&
            mn[1]!=ln[2] && mn[1]!=ln[1] &&mn[1]!=ln[0] && mn[0]!=ln[3] && mn[0]!=ln[2] && mn[0]!=ln[1] &&mn[0]!=ln[0])
        printf("恭喜中特別獎\n");
        else
        printf("恭喜沒中獎\n");
    }





    system("pause");
    return 0;
}


