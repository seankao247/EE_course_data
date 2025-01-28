#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int i;
    double sum=0;
    for(i = 1 ; i <= 9999999 ; i++)
    {
            sum = sum + pow(-1,i+1)*(1./(2*i-1));
    }
    printf("pi = %.16f",4*sum);
    return 0;
}
