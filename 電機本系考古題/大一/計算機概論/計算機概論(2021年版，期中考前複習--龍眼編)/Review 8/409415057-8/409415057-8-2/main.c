#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[7] ={0,0,0,0,0,0,0};
    int b[5] ={0,0,0,0,0};
    int i,x1,x2,y1,y2,z1,z2;
    int total = 0;
    FILE*input1;
    FILE*input2;
    input1 = fopen("Player1.txt","r");
    input2 = fopen("Player2.txt","r");
    fscanf(input1,"%d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]);
    fscanf(input2,"%d %d %d %d %d",&b[0],&b[1],&b[2],&b[3],&b[4]);

    for(i = 0;i < 5;i++)
    {
        printf("Player 1 number:%d\n",a[i]);
        printf("Player 2 number:%d\n",b[i]);
        x1 = a[i]/100;
        y1 = (a[i]%100)/10;
        z1 = (a[i]%100)%10;
        x2 = b[i]/100;
        y2 = (b[i]%100)/10;
        z2 = (b[i]%100)%10;
        if(x1 > x2)
        {
            total++;
        }
        if(x1 < x2)
        {
            total--;
        }
        if(y1 > y2)
        {
            total++;
        }
        if(y1 < y2)
        {
            total--;
        }
        if(z1 > z2)
        {
            total++;
        }
        if(z1 < z2)
        {
            total--;
        }
        switch(total)
    {
        case 3:  printf("Win three\n");  break;
        case 2:  printf("Win two\n");    break;
        case 1:  printf("Win one\n");    break;
        case 0:  printf("Tie\n");        break;
        case -1: printf("Lose one\n");   break;
        case -2: printf("Lose two\n");   break;
        case -3: printf("Lose three\n"); break;
    }
        total=0;
    }

    return 0;
}
