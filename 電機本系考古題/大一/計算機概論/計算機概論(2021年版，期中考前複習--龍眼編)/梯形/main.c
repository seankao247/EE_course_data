#include <stdio.h>
#include <stdlib.h>

int main()
{
    int u,d,U,D,floor,F,J=0;
    printf("upper bound : ");
    scanf("%d",&u);
    printf("down bound : ");
    scanf("%d",&d);
    system("cls");
    if((u>d)&&(u%2==d%2))
    {
        floor=(u-d)/2+1;
        for(floor;floor>0;floor--)
        {
            F=J;
            for(F;F>0;F--)
            {
                printf(" ");
            }
            U=u;
            for(U;U>0;U--)
            {
                printf("A");
            }
            printf("\n");
            u=u-2;
            J++;
        }
    }
    else if((u<d)&&(u%2==d%2))
    {
        floor=(d-u)/2+1;
        for(floor;floor>0;floor--)
        {
            F=floor-1;
            for(F;F>0;F--)
            {
                printf(" ");
            }
            U=u;
            for(U;U>0;U--)
            {
                printf("A");
            }
            printf("\n");
            u=u+2;
        }
    }
    else
    {
        printf("\nERROR");
    }
    return 0;
}
