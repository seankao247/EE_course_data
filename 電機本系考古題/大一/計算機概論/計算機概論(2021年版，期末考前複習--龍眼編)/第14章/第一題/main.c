#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,i;
    double sum=0;
    printf("½Ð¿é¤Jn­È : ");
    scanf("%d",&n);
    if(n == 0)
    {
        sum = 0;
    }
    else
    {
        for(i = 1 ; i <= n ; i++)
        {
            sum = sum + pow(-1,i+1)*(1./(2*i-1));
        }
    }
    printf("pi = %.16f",4*sum);
    return 0;
}
