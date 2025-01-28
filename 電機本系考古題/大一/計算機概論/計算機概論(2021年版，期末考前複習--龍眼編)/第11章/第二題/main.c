#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[25]={0},check[26]={0};
    int array[5][5],x,y;
    srand(time(0));
    int i=0,step=0;
    int m=0,n=0;
    while(i<25)
    {
        a[i]=rand()%25+1;
        if(check[a[i]]==0)
        {
            check[a[i]]=1;
            i++;
        }
    }
    for(x=0;x<5;x++)//一維換二維
    {
        for(y=0;y<5;y++)
        {
            array[x][y]=a[5*x+y];
        }
    }
    printf("小銘現在要抄近路回家:\n");
    for(x=0;x<5;x++)//把二維印出來
    {
        for(y=0;y<5;y++)
        {
            printf("%4d",array[x][y]);
        }
        printf("\n");
    }
    printf("\n走的過程:\n\n");
    while(m<5&&n<5)
    {
        if(m==4&&n==4)
        {
            step = step - array[m][n];
            break;
        }
        else if(m==4&&n!=4)
        {
            step = step + array[m][n+1];
            printf("往右到 %d\n",array[m][n+1]);
            n=n+1;
        }
        else if(m!=4&&n==4)
        {
            step = step + array[m+1][n];
            printf("往下到 %d\n",array[m+1][n]);
            m=m+1;
        }
        else if(array[m+1][n]>array[m][n+1])
        {
            step = step + array[m][n+1];
            printf("往右到 %d\n",array[m][n+1]);
            n=n+1;
        }
        else if(array[m+1][n]<array[m][n+1])
        {
            step = step + array[m+1][n];
            printf("往下到 %d\n",array[m+1][n]);
            m=m+1;
        }

    }
    printf("\n\n經過一番波折小銘終於回到家了\n");
    printf("他總共走了%d步",step);

    return 0;
}
