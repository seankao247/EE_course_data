#include <stdio.h>
#include <stdlib.h>

int main()
{
    int u,d,J,zero=0,i,I;
    while(1){
    printf("�W���G");
    scanf("%d",&u);
    printf("�U���G");
    scanf("%d",&d);
    if((u>d)&&(u%2==d%2))
        {
        J=(((u-d)/2)+1);
        for(;J>0;J--)
            {
            i=zero;
            for(;i>0;i--)
                {
                printf(" ");
                }
            I=u;
            for(;I>0;I--)
                {
                printf("*");
                }
            printf("\n");
            zero++;
            u=u-2;
            }
            break;
        }
    else if((u<d)&&(u%2==d%2))
        {
        J=(((d-u)/2)+1);
        for(;J>0;J--)
            {
            i=J-1;
            for(;i>0;i--)
                {
                printf(" ");
                }
            I=u;
            for(;I>0;I--)
                {
                printf("*");
                }
            printf("\n");
            u=u+2;
            }
            break;
        }
    else
    {
    printf("�����A�n��J���T��\n");
    printf("�o�ؤW���U���̦n�O�i�H�����\n\n");
    }
    }
    return 0;
}
