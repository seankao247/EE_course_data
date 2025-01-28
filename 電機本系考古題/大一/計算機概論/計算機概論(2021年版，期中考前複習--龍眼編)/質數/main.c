
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n[5]={0};
    int i=0,divisor=1;
    int c_m=0,p_m=0;
    int max=0,min=999999;
    printf("Please input five number:\n");
    scanf("%d %d %d %d %d",&n[0],&n[1],&n[2],&n[3],&n[4]);
    printf("\n\nLoading...\n\n");
    printf("Prime Number :");

    for(i=0;i<5;i++)
    {
        for(;;)
        {
            divisor++;
            if((n[i]%divisor==0)&&(n[i]!=divisor))
            {
                divisor =1;
                c_m++;
                break;
            }
            else if((n[i]%divisor==0)&&(n[i]==divisor))
            {
                printf("%4d",n[i]);
                p_m++;
                if(n[i]>max)
                {
                    max = n[i];
                }
                if(n[i]<min)
                {
                    min = n[i];
                }
                divisor = 1;
                break;
            }

        }
        if(i==4)
        {
            printf("\n");
        }
    }
    printf("The quantity of Prime Number: %4d\n",p_m);
    printf("The quantity of Composite Number : %4d\n",c_m);
    printf("Maximum of the list  : %4d\n",max);
    printf("Minimum of the list: %4d\n",min);
    return 0;
}
