#include <stdio.h>
#include <stdlib.h>

/*���D�O�n�����@�Ʀrn�A�D�X��������O�i�����ƦC(Fibonacci sequence)*/
/*��ƦC�� 0 1 1 2 3 5 8 13 21 34 55 89 144 ....*/
int fi(int);   //�ƦC�ƨ禡(Sub-function for transfering n into the result of Fibonacci  sequence)
int main()
{
    int n,i;
    printf("�п�Jn : ");
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
