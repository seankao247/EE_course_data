#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[10];
    int i;
    int divisor=1;
    int remainder;
    int number=0,maximum=0,minimum=1000;
    int n=0,m=0;
    FILE*random;
    random=fopen("random.txt","r");
    fscanf(random,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]);
    printf("the number you input:\n%d %d %d %d %d %d %d %d %d %d",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
    printf("\nprime number:\n");
    for (i=0;i<10;i++)
    {
        n=a[i];
        for(;;)
        {
            divisor++;
            //printf("divisor is %d\n",divisor);
            if((n%divisor==0)&&(n!=divisor))//合數
            {
             divisor=1;
             m++;
             break;
            }
            else if((n%divisor==0)&&(n==divisor))//質數
            {
             printf("%5d",a[i]);
             if(a[i]>maximum)
                {
                maximum=a[i];
                }
             if(a[i]<minimum)
                {
                minimum=a[i];
                }
             number++;
             divisor=1;
             break;
            }
        }
        if(i==9)
            {
            printf("\n");
            }
    }
    printf("maximum number:%d\n",maximum);
    printf("minimum number:%d\n",minimum);
    printf("the quantity of prime number:%d\n",number);
    printf("the quantity of composite number:%d" ,m);
    return 0;
}
