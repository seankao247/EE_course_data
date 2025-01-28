#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k;
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            k=i*j;
            printf("%d*%d=%2d\t",i,j,k);
        }
        printf("\n");
    }
    return 0;
}
