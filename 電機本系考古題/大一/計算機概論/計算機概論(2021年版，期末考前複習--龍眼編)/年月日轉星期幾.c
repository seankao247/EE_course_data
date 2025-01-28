#include <stdio.h>
#include <stdlib.h>
/*小提醒:先把想要的日期(年月日)打在資料夾的date.txt再執行*/
/*reminder:please input the "year","month","day" in the file called "date.txt" in this folder.*/
/*程式跑完，結果會顯示在day.txt裡*/
/*Waiting for the program finished , the result will be displayed in the file called "day.txt" in this folder.*/
int main()
{
    int y,m,d,yy;
    int count = 0,x;
    FILE*input;
    FILE*output;
    input = fopen("date.txt","r");
    output = fopen("day.txt","w");
    fscanf(input,"%d %d %d",&y,&m,&d);//讀取年月日
    yy = y;
    for(y=y-1;y>=1900;y--)//先算年
    {
        if(((y%4==0)&&(y%100==0)&&(y%400==0))||((y%4==0)&&(y%100!=0)))//閏年
        {
            count = count + 366;
        }
        else//平年
        {
            count = count + 365;
        }
    }
    y = yy;
    for(m;m>=1;m--)//再算月
    {
        if((m==2)||(m==4)||(m==6)||(m==8)||(m==9)||(m==11))//1、3、5、7、8、10月總共有31天
        {
            count = count + 31 ;
        }
        else if((m==5)||(m==7)||(m==10)||(m==12))//4、6、9、11月總共有30天
        {
            count = count + 30;
        }
        else if(m==3)//2月要判斷是否為閏年
        {
            if(((y%4==0)&&(y%100==0)&&(y%400==0))||((y%4==0)&&(y%100!=0)))//閏年加29天
            {
                count = count + 29;
            }
            else//平年加28天
            {
                count = count + 28;
            }
        }
    }
    count = count + d;
    printf("The Answer is in the file called day.txt");
    x = count%7;
    switch(x)
    {
        case 0:
            fprintf(output,"Today is Sunday.");
            break;
        case 1:
            fprintf(output,"Today is Monday.");
            break;
        case 2:
            fprintf(output,"Today is Tuesday.");
            break;
        case 3:
            fprintf(output,"Today is Wednesday.");
            break;
        case 4:
            fprintf(output,"Today is Thursday.");
            break;
        case 5:
            fprintf(output,"Today is Friday.");
            break;
        case 6:
            fprintf(output,"Today is Saturday.");
            break;
    }
    return 0;
}
