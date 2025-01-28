#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[25]={0};
    int check[200]={0},i=0;
    int j,x,y;
    srand(time(0));
    while(i<25)
    {
        a[i]=rand()%51+150;
        if(check[a[i]]==0)
        {
            check[a[i]]=1;
            i++;
        }
    }
    printf("班上25位同學:\n");
    for(j=0;j<25;j++)
    {
        printf("%d ",a[j]);
    }
    printf("\n");
    for(i=0;i<24;i++)
    {
        for(j=0;j<24-i;j++)
        {
            if(a[j]<a[j+1])
            {
                int tem = a[j];
                a[j]=a[j+1];
                a[j+1]=tem;
            }
        }
    }
    printf("按照身高來排:\n");
    for(i=0;i<25;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("大合照:\n");
    int array[5][5];
    for(x=0;x<5;x++)
    {
        for(y=0;y<5;y++)
        {
            array[x][y]=a[5*x+y];
            printf("%d ",array[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
