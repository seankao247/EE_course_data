#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,c;
    int x1,x2,x;
    int D;
    printf("a : ");
    scanf("%d",&a);
    printf("b : ");
    scanf("%d",&b);
    printf("c : ");
    scanf("%d",&c);

    D = ( b * b )-(4 * a * c);
    x1 = (-b + sqrt(D) )/(2 * a);
    x2 = (-b - sqrt(D) )/(2 * a);
    if(x2 > x1)
    {
        x = x1;
        x1 = x2;
        x2 = x;
    }

    if(D > 0)
    {
         printf("��ո�\n");
         printf("���j���� : %d\n",x1);
         printf("���p���� : %d",x2);
    }
    else if(D == 0)
    {
        printf("�@�ո�\n");
        printf("�ߤ@�� : %d",x1);
    }
    else
    {
        printf("�L��");
    }


    return 0;
}
