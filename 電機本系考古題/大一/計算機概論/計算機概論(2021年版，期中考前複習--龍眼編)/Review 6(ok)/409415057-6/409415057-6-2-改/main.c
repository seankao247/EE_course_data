#include <stdio.h>
#include <stdlib.h>

int main()
{
    int u,d,J,zero=0,i,I;
    while(1){
    printf("上底：");
    scanf("%d",&u);
    printf("下底：");
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
    printf("媽的你要輸入正確啊\n");
    printf("這種上底下底最好是可以有梯形\n\n");
    }
    }
    return 0;
}
