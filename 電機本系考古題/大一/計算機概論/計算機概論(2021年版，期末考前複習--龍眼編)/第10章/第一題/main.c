#include <stdio.h>
#include <stdlib.h>

/*此題是要給予一數字n，求出其對應的費波那契數列(Fibonacci sequence)*/
/*其數列為 0 1 1 2 3 5 8 13 21 34 55 89 144 ....*/
int fi(int);   //數列副函式(Sub-function for transfering n into the result of Fibonacci  sequence)
int main()
{
    int n,i;
    printf("請輸入n : ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("%d\n",fi(i));
    }
    return 0;
}

int fi(int n)
{
    if(n==1)
    {
        return 0;
    }
    if((n==2)||(n==3))
    {
        return 1;
    }
    else
    {
        return fi(n-1)+fi(n-2);
    }
}
