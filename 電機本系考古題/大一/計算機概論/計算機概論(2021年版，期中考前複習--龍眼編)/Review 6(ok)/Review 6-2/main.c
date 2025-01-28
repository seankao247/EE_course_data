#include <stdio.h>
#include <stdlib.h>

int main()//build a trapezoid
{
    int u,d;//upper base and lower base
    int J;
    int a,A=0;
    int b;

    while(1)
    {
        printf("上底:");
        scanf("%d",&u);// upper base
        printf("下底:");
        scanf("%d",&d);// lower base

        if((u>d)&&(u%2==d%2))// upper > lower && upper and lower base both must be odd number or even number
            {
                J=((u-d)/2+1);//calculate the floor of the trapezoid
                for(J;J>0;J--)
                {
                    a = A;
                    for(a;a>0;a--)
                    {
                        printf(" ");//put space first
                    }
                    b = u;
                    for(b;b>0;b--)
                    {
                        printf("*");
                    }
                    printf("\n");
                    A++;
                    u=u-2;
                }
                break;
            }
        else if ((u<d)&&(u%2==d%2))
        {
            J=((d-u)/2+1);
            for(J;J>0;J--)
            {
                a = J-1;
                for(a;a>0;a--)
                {
                    printf(" ");//put space first
                }
                b = u;
                for(b;b>0;b--)
                {
                    printf("*");
                }
                u=u+2;
                printf("\n");

            }
            break;
        }
        else
        {
            printf("條件不符請重新輸入\n");
        }

    }
    return 0;
}
