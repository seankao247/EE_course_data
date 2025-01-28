#include <stdio.h>
#include <stdlib.h>

void computer(int);
int max = 1000,min = 1;
int data,count=1;
int main()
{
    srand(time(NULL));
    data=rand()%1000+1;
    printf("電腦選%d\n",data);
    for(;;)
    {
        int guess;
        printf("第%d回合\n",count);
        for(;;)
        {
            printf("請輸入%d到%d之內的數字:",min,max);
            scanf("%d",&guess);
            if(guess==data)
            {
                break;
            }
            else if((guess>=min)&&(guess<=max))
            {
                computer(guess);
                break;
            }
            else
            {
                printf("你是不是眼殘阿\n");
                printf("請重新輸入範圍內的數字\n");
            }
        }
        if(guess==data)
        {
            printf("幹你終於猜對了\n");
            printf("你花了%d幾回合",count);
            break;
        }
    }
    return 0;
}
void computer(int number)
{
    if((number>data)&&(number<=max))
    {
        printf("太大了");
        max = number-1;
    }
    if((number<data)&&(number>=min))
    {
        printf("大小了");
        min = number+1;
    }
    count++;
    printf("\n");
}
