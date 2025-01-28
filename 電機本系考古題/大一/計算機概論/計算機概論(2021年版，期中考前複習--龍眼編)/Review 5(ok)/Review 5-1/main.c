#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int times[7]={0};
    int i,I,number=0;
    srand(time(NULL));
    for(i=1;i<=6000;i++)
    {
        number = rand()%6+1;
        times[number]++;
    }
    printf("%5s%10s\n","抽到數字","抽到次數");
    for(I=1;I<=6;I++)
    {
        printf("%5d%10d\n",I,times[I]);
    }
    return 0;
}
